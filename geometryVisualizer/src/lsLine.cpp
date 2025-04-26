#include "lsLine.h"
#include "IRenderContext.h"

#include <wx/colour.h>

lsLine::lsLine()
    : s(lsPoint(0, 0))
    , e(lsPoint(0, 0))
{
}

lsLine::lsLine(const lsPoint& s_, const lsPoint& e_)
    : s(s_)
    , e(e_)
{

}

lsLine::lsLine(const lsLine& other)
    : s(other.s)
    , e(other.e)
{

}

void lsLine::draw(IRenderContext& renderer) const
{
    RenderStyle style;
    style.color = bSelected ? *wxCYAN : *wxRED; // 选中时绿色边框
    style.fillColor = bSelected ? *wxCYAN : *wxRED;
    // style.lineWidth = bSelected ? 3 : 1;
    style.lineWidth = 1;
    renderer.draw_line({s.x, s.y}, {e.x, e.y}, style);
}

bool lsLine::hit_test(const lsPoint& p) const
{
    // 横平竖直的线段不好使
    // 测试点是否在线段上
    lsReal tol = 2;
    lsReal minx = std::min(s.x, e.x) - tol;
    lsReal maxx = std::max(s.x, e.x) + tol;
    lsReal miny = std::min(s.y, e.y) - tol;
    lsReal maxy = std::max(s.y, e.y) + tol;
    if (p.x < minx || p.x > maxx || p.y < miny || p.y > maxy)
        return false;

    lsPoint ps, pe;
    ps.x = s.x - p.x;
    ps.y = s.y - p.y;
    pe.x = e.x - p.x;
    pe.y = e.y - p.y;

    lsReal len0 = std::sqrt(ps.x * ps.x + ps.y * ps.y);
    lsReal len1 = std::sqrt(pe.x * pe.x + pe.y * pe.y);
    ps.x /= len0;
    ps.y /= len0;
    pe.x /= len1;
    pe.y /= len1;

    // 同向
    lsReal cross = std::abs(ps.x * pe.y - ps.y * pe.x);
    if (cross < 0.5)
        return true;
    return false;
}
