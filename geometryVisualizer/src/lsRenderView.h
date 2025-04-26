#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include "lsDocument.h"

#include "WxRenderContext.h"

class lsRenderView : public wxPanel
{
public:
    lsRenderView(wxWindow* parent) : wxPanel(parent)
    {
        SetBackgroundStyle(wxBG_STYLE_PAINT);
        SetBackgroundColour(*wxBLACK);

        Bind(wxEVT_PAINT, &lsRenderView::OnPaint, this);
        Bind(wxEVT_LEFT_DOWN, &lsRenderView::OnMouseDown, this);
        Bind(wxEVT_KEY_DOWN, &lsRenderView::OnKeyDown, this);
    }
    
    void set_document(lsDocument* doc)
    {
        m_doc = doc; Refresh();
    }

    void set_selection_mode(bool bInSingleSelectMode)
    {
        m_bInSingleSelectMode = bInSingleSelectMode;
        SetCursor(bInSingleSelectMode ? wxCURSOR_HAND : wxCURSOR_ARROW);
        Refresh();
    }

private:
    void OnPaint(wxPaintEvent& event)
    {
        wxAutoBufferedPaintDC dc(this);
        dc.Clear();

        if (!m_doc)
            return;

        WxRenderContext renderer(dc);
        for (const auto& layer : m_doc->get_layers())
        {
            if (!layer->is_visible())
                continue;

            for (const auto& entity : layer->get_entitys())
            {
                entity->draw(renderer);
            }
        }
    }
    
    void OnMouseDown(wxMouseEvent& event)
    {
        if (!m_doc)
            return;
        if (!m_bInSingleSelectMode)
            return;

        wxPoint pos = event.GetPosition();
        lsPoint mousePos(pos.x, pos.y);
        bool bCtrl = event.ControlDown();

        if (!bCtrl)
        {
            // 非追加选择状态，清空选择集
            m_doc->clear_selection();
        }

        bool bHitAny = false;
        const auto& layers = m_doc->get_layers();
        for (auto it = layers.rbegin(); it != layers.rend(); ++it)
        {
            for (auto& entity : (*it)->get_entitys())
            {
                if (entity->hit_test(mousePos))
                {
                    m_doc->sel_entity(entity->get_id());
                    bHitAny = true;
                    break;
                }
            }

            if (bHitAny)
                break;
        }

        // 重绘
        Refresh();
    }

    void OnKeyDown(wxKeyEvent& event)
    {
        switch (event.GetKeyCode())
        {
        case WXK_ESCAPE:
        {
            if (m_bInSingleSelectMode)
            {
                set_selection_mode(false);
            }
            else
            {
                // 发生了清除选择集，要重绘
                bool bSelected = m_doc->is_selected();
                m_doc->clear_selection();
                if (bSelected)
                    Refresh();
            }
        }
        break;
        }
        event.Skip();
    }

    lsDocument* m_doc = nullptr;

    // 是否处于单选状态
    bool m_bInSingleSelectMode = false;
};