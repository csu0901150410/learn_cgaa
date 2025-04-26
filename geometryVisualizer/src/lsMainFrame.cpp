#include "lsMainFrame.h"

#include <wx/artprov.h>

#include <wx/filedlg.h>
#include <wx/msgdlg.h>

#include <fstream>

#include "lsLine.h"

// 自定义菜单项ID
enum {
    ID_AddLine = wxID_HIGHEST + 1,
    ID_SelectElement
};

lsMainFrame::lsMainFrame()
    : wxFrame(nullptr, wxID_ANY, "Geometry Visualizer")
{
    SetMinSize(wxSize(800, 600));

    // 初始化文档和视图
    InitDocument();
    
    // 创建UI
    CreateMenuBar();
    
    // 设置窗口图标
    SetIcon(wxICON(app_icon));  // 需提供图标资源

    Bind(wxEVT_PAINT, &lsMainFrame::OnPaint, this);
    Bind(wxEVT_MENU, &lsMainFrame::OnAddLine, this, ID_AddLine);
    Bind(wxEVT_MENU, &lsMainFrame::OnSingleSelection, this, ID_SelectElement);
}

void lsMainFrame::OnPaint(wxPaintEvent &event)
{
    wxSize size = GetClientSize();
    int a = 10;
}

// 初始化文档数据
void lsMainFrame::InitDocument()
{
    m_document = std::make_unique<lsDocument>();
    
    // 添加默认图层和示例图元
    auto layer = m_document->add_layer(std::make_unique<lsLayer>("Default"));
        layer->append_entity(std::make_unique<lsLine>(lsPoint(50, 50), lsPoint(150, 150)));
    
    // 创建渲染视图并绑定文档
    m_renderView = new lsRenderView(this);
    m_renderView->set_document(m_document.get());
    
    // 布局
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_renderView, 1, wxEXPAND);
    SetSizer(sizer);
    Fit();

    Layout();
}

// 创建菜单栏
void lsMainFrame::CreateMenuBar()
{
    m_menuBar = new wxMenuBar;
    
    // File 菜单
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_NEW, "&New\tCtrl+N");
    fileMenu->Append(wxID_OPEN, "&Open\tCtrl+O");
    fileMenu->Append(wxID_SAVE, "&Save\tCtrl+S");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt+F4");
    m_menuBar->Append(fileMenu, "&File");
    
    // Edit 菜单
    wxMenu* editMenu = new wxMenu;
    editMenu->Append(wxID_UNDO, "&Undo\tCtrl+Z");
    editMenu->Append(wxID_REDO, "&Redo\tCtrl+Y");
    editMenu->AppendSeparator();
    editMenu->Append(ID_AddLine, "Add &Line");
    m_menuBar->Append(editMenu, "&Edit");

    // Selection 菜单
    wxMenu* selectionMenu = new wxMenu;
    selectionMenu->Append(ID_SelectElement, "Select");
    m_menuBar->Append(selectionMenu, "&Selection");
    
    SetMenuBar(m_menuBar);
}

// --- 事件处理函数 ---

// 新建文档
void lsMainFrame::OnNew(wxCommandEvent& event)
{
    m_document = std::make_unique<lsDocument>();
    m_renderView->set_document(m_document.get());
    m_renderView->Refresh();
}

// 打开文件
void lsMainFrame::OnOpen(wxCommandEvent& event)
{
    wxFileDialog dialog(this, "Open Document", "", "", 
                        "JSON Files (*.json)|*.json", wxFD_OPEN);
    if (dialog.ShowModal() == wxID_OK)
    {
        std::ifstream file(dialog.GetPath().ToStdString());
        
        m_renderView->Refresh();
    }
}

// 保存文件
void lsMainFrame::OnSave(wxCommandEvent& event)
{
    wxFileDialog dialog(this, "Save Document", "", "", 
                        "JSON Files (*.json)|*.json", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (dialog.ShowModal() == wxID_OK)
    {
        std::ofstream file(dialog.GetPath().ToStdString());
    }
}

// 退出程序
void lsMainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

// 添加图元
void lsMainFrame::OnAddLine(wxCommandEvent& event)
{
    // auto layer = m_document->add_layer(std::make_unique<lsLayer>("Layer " + std::to_string(m_document->get_layers().size() + 1)));
    // layer->append_entity(std::make_unique<lsLine>(lsPoint(200, 100), lsPoint(200, 200)));
    // m_renderView->Refresh();

    if (m_document->get_layers().empty())
        return;
    auto layer = m_document->get_work_layer();
    layer->append_entity(std::make_unique<lsLine>(lsPoint(200, 100), lsPoint(200, 200)));
    m_renderView->Refresh();
}

void lsMainFrame::OnSingleSelection(wxCommandEvent &event)
{
    m_renderView->set_selection_mode(true);
}

// 撤销操作
void lsMainFrame::OnUndo(wxCommandEvent& event)
{
    
}

// 重做操作
void lsMainFrame::OnRedo(wxCommandEvent& event)
{
    
}
