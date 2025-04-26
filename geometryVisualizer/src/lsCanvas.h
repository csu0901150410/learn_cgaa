#pragma once

#include <wx/wx.h>

class lsCanvas : public wxPanel
{
public:
    lsCanvas(wxWindow* parent);
    
    void OnPaint(wxPaintEvent& event);
};
