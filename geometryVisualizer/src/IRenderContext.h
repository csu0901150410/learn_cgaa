#pragma once
#include <wx/colour.h>
#include <wx/gdicmn.h>
#include <wx/affinematrix2d.h>

#include "lsPoint.h"

// 绘图样式配置
struct RenderStyle
{
    wxColour color = *wxBLACK;      // 边框颜色
    wxColour fillColor = *wxWHITE;  // 填充颜色
    int lineWidth = 1;              // 线宽
};

// 抽象渲染接口
class IRenderContext
{
public:
    virtual ~IRenderContext() = default;

    // 基本图元绘制
    virtual void draw_line(const lsPoint& start, const lsPoint& end, const RenderStyle& style) = 0;
    virtual void draw_rect(const lsPoint& topLeft, const lsPoint& bottomRight, const RenderStyle& style) = 0;
    virtual void draw_circle(const lsPoint& center, int radius, const RenderStyle& style) = 0;
    virtual void draw_polygon(const lsPoint* points, int n, const RenderStyle& style) = 0;

    // 状态控制
    virtual void set_transform(const wxAffineMatrix2D& matrix) = 0;  // 坐标变换
    virtual void push_state() = 0;   // 保存当前状态（如颜色、变换）
    virtual void pop_state() = 0;     // 恢复上次保存的状态
};