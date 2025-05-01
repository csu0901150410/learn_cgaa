#include "lsMainFrame.h"

#include <wx/artprov.h>

#include <wx/filedlg.h>
#include <wx/msgdlg.h>

#include <fstream>

lsMainFrame::lsMainFrame()
    : wxFrame(nullptr, wxID_ANY, "Geometry Visualizer")
{
    SetMinSize(wxSize(800, 600));
    
    // 创建UI
    CreateMenuBar();
    
    // 设置窗口图标
    SetIcon(wxICON(app_icon));  // 需提供图标资源

    Bind(wxEVT_CLOSE_WINDOW, &lsMainFrame::OnClose, this);
    Bind(wxEVT_PAINT, &lsMainFrame::OnPaint, this);
    Bind(wxEVT_SIZE, &lsMainFrame::OnSize, this);
    Bind(wxEVT_MOUSEWHEEL, &lsMainFrame::OnWheel, this);
    Bind(wxEVT_MOTION, &lsMainFrame::OnMouseMove, this);
    Bind(wxEVT_LEFT_DOWN, &lsMainFrame::OnMouseLeftDown, this);

    Bind(wxEVT_MENU, &lsMainFrame::OnQuit, this, ID_MenuQuit);
    Bind(wxEVT_MENU, &lsMainFrame::OnOpen, this, ID_MenuOpen);
    Bind(wxEVT_MENU, &lsMainFrame::OnFit, this, ID_MenuFit);
}

void lsMainFrame::OnPaint(wxPaintEvent &event)
{

}

void lsMainFrame::OnSize(wxSizeEvent& event)
{

}

void lsMainFrame::OnWheel(wxMouseEvent& event)
{

}

void lsMainFrame::OnMouseMove(wxMouseEvent& event)
{

}

void lsMainFrame::OnMouseLeftDown(wxMouseEvent& event)
{

}

// 创建菜单栏
void lsMainFrame::CreateMenuBar()
{
    m_menuBar = new wxMenuBar;
    
    // File 菜单
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(ID_MenuOpen, "&Open\tCtrl+O");
    fileMenu->AppendSeparator();
    fileMenu->Append(ID_MenuQuit, "Q&uit\tAlt+F4");
    m_menuBar->Append(fileMenu, "&File");
    
    // Edit 菜单
    wxMenu* editMenu = new wxMenu;
    m_menuBar->Append(editMenu, "&Edit");

    // View 菜单
    wxMenu* viewMenu = new wxMenu;
    viewMenu->Append(ID_MenuFit, "Fit Contents");
    m_menuBar->Append(viewMenu, "&View");
    
    SetMenuBar(m_menuBar);

    SetBackgroundColour(*wxBLACK);
}

// --- 事件处理函数 ---

// 打开文件
void lsMainFrame::OnOpen(wxCommandEvent& event)
{
    
}

void lsMainFrame::OnFit(wxCommandEvent& event)
{

}

// 关闭窗口
void lsMainFrame::OnClose(wxCloseEvent& event)
{
    Destroy();
}

// 退出程序
void lsMainFrame::OnQuit(wxCommandEvent& event)
{
    Destroy();
}


