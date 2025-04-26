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
    }
    
    void set_document(lsDocument* doc)
    {
        m_doc = doc; Refresh();
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
                bool isSelected = m_doc->is_selected(entity->get_id());
                entity->draw(renderer, isSelected);
            }
        }
    }
    
    void OnMouseDown(wxMouseEvent& event)
    {
        wxPoint pos = event.GetPosition();
        // 检测选中逻辑...
        Refresh();
    }

    lsDocument* m_doc = nullptr;
};