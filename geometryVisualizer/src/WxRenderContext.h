#pragma once
#include "IRenderContext.h"
#include <wx/dc.h>

// wxWidgets 的渲染实现
class WxRenderContext : public IRenderContext
{
public:
    explicit WxRenderContext(wxDC& dc) : m_dc(dc) {}

// 实现接口
public:
    void draw_line(const lsPoint& start, const lsPoint& end, const RenderStyle& style) override;
    void draw_rect(const lsPoint& topLeft, const lsPoint& bottomRight, const RenderStyle& style) override;
    void draw_circle(const lsPoint& center, int radius, const RenderStyle& style) override;
    void draw_polygon(const lsPoint* points, int n, const RenderStyle& style) override;

    void set_transform(const wxAffineMatrix2D& matrix) override;
    void push_state() override;
    void pop_state() override;

private:
    wxDC& m_dc;                      // 引用 wxWidgets 绘图上下文
    wxAffineMatrix2D m_transform;    // 当前变换矩阵
    std::vector<wxGraphicsContext*> m_stateStack; // 状态栈（用于 Push/Pop）
};