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

void lsLine::draw(IRenderContext& renderer, bool isSelected) const
{
    RenderStyle style;
    style.color = isSelected ? *wxGREEN : *wxRED; // 选中时绿色边框
    style.fillColor = *wxRED;
    style.lineWidth = isSelected ? 3 : 1;
    renderer.draw_line({s.x, s.y}, {e.x, e.y}, style);
}

bool lsLine::hit_test(const lsPoint& p) const
{
    return false;
}
