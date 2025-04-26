#pragma once

#include <wx/wx.h>
#include "lsCanvas.h"

class lsMainFrame : public wxFrame
{
public:
    lsMainFrame();

    void OnExit(wxCommandEvent& event);
    
    void OnConvexHull(wxCommandEvent& event);

private:
    lsCanvas* m_canvas;
};
