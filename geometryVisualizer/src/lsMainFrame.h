#pragma once

#include <wx/wx.h>
#include <memory>
#include "lsDocument.h"
#include "lsRenderView.h"

class lsMainFrame : public wxFrame
{
public:
    lsMainFrame();

    void OnPaint(wxPaintEvent& event);

// ui相关
private:
    wxMenuBar* m_menuBar;

    void CreateMenuBar();

    // 事件处理函数
    void OnNew(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    
    void OnUndo(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);

    void OnAddLine(wxCommandEvent& event);
    void OnSingleSelection(wxCommandEvent& event);

private:
    std::unique_ptr<lsDocument> m_document;
    lsRenderView* m_renderView;

    void InitDocument();
};
