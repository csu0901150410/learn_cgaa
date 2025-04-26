#include "lsMainFrame.h"

lsMainFrame::lsMainFrame()
    : wxFrame(nullptr, wxID_ANY, "Geometry Visualizer")
{
    SetDoubleBuffered(true);
    SetMinSize(wxSize(800, 600));

    // 创建菜单栏
    wxMenuBar* menuBar = new wxMenuBar();
    
    wxMenu* fileMenu = new wxMenu();
    fileMenu->Append(wxID_EXIT, "Exit");

    wxMenu* algoMenu = new wxMenu();
    algoMenu->Append(wxID_ANY, "Convex Hull");

    menuBar->Append(fileMenu, "File");
    menuBar->Append(algoMenu, "Algorithms");

    SetMenuBar(menuBar);

    // 绑定事件
    Bind(wxEVT_MENU, &lsMainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &lsMainFrame::OnConvexHull, this, wxID_ANY);

    m_canvas = new lsCanvas(this);
    m_canvas->SetSize(wxSize(800, 600));
    m_canvas->SetBackgroundColour(wxColour(0, 0, 0));

    // 布局
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(m_canvas, 1, wxEXPAND);
    SetSizer(sizer);
}

void lsMainFrame::OnExit(wxCommandEvent &event)
{
    Close();
}

void lsMainFrame::OnConvexHull(wxCommandEvent &event)
{
    wxMessageBox("Convex Hull");
}
