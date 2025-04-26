#include "WxRenderContext.h"
#include <wx/graphics.h>  // wxGraphicsContext

void WxRenderContext::draw_line(const lsPoint& start, const lsPoint& end, const RenderStyle& style)
{
    m_dc.SetPen(wxPen(style.color, style.lineWidth));
    m_dc.DrawLine({(int)start.x, (int)start.y}, {(int)end.x, (int)end.y});
}

void WxRenderContext::draw_rect(const lsPoint& topLeft, const lsPoint& bottomRight, const RenderStyle& style)
{
    m_dc.SetPen(wxPen(style.color, style.lineWidth));
    m_dc.SetBrush(wxBrush(style.fillColor));
    m_dc.DrawRectangle({(int)topLeft.x, (int)topLeft.y}, wxSize(bottomRight.x - topLeft.x, bottomRight.y - topLeft.y));
}

void WxRenderContext::draw_circle(const lsPoint& center, int radius, const RenderStyle& style)
{
    m_dc.SetPen(wxPen(style.color, style.lineWidth));
    m_dc.SetBrush(wxBrush(style.fillColor));
    m_dc.DrawCircle({(int)center.x, (int)center.y}, radius);
}

void WxRenderContext::draw_polygon(const lsPoint* points, int n, const RenderStyle& style)
{
    m_dc.SetPen(wxPen(style.color, style.lineWidth));
    m_dc.SetBrush(wxBrush(style.fillColor));
    wxPoint *polygon = new wxPoint[n];
    for (int i = 0; i < n; ++i)
        polygon[i] = wxPoint(points[i].x, points[i].y);
    m_dc.DrawPolygon(n, polygon);
    delete[] polygon;
}

void WxRenderContext::set_transform(const wxAffineMatrix2D& matrix)
{
    if (auto gc = wxGraphicsContext::CreateFromUnknownDC(m_dc))
    {
        gc->SetTransform(gc->CreateMatrix(matrix));
        delete gc;
    }
    m_transform = matrix;
}

void WxRenderContext::push_state() {
    if (auto gc = wxGraphicsContext::CreateFromUnknownDC(m_dc))
    {
        m_stateStack.push_back(gc);
        gc->PushState();
    }
}

void WxRenderContext::pop_state()
{
    if (!m_stateStack.empty())
    {
        auto gc = m_stateStack.back();
        gc->PopState();
        delete gc;
        m_stateStack.pop_back();
    }
}