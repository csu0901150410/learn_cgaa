#pragma once

#include <wx/wx.h>
#include <memory>

class lsMainFrame : public wxFrame
{
public:
    lsMainFrame();

// ui相关
private:
	// 自定义菜单项ID
	enum {
		ID_MenuQuit = wxID_HIGHEST + 1,
        ID_MenuOpen,
        ID_MenuFit
	};

    // 事件处理函数
    void OnClose(wxCloseEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnFit(wxCommandEvent& event);

    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnWheel(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnMouseLeftDown(wxMouseEvent& event);

private:
    wxMenuBar* m_menuBar;
    void CreateMenuBar();
};
