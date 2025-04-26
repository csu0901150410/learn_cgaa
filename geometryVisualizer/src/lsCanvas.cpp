#include "lsCanvas.h"

lsCanvas::lsCanvas(wxWindow *parent)
    : wxPanel(parent)
{
    Bind(wxEVT_PAINT, &lsCanvas::OnPaint, this);
}

void lsCanvas::OnPaint(wxPaintEvent &event)
{
    
}
