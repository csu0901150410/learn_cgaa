#include <wx/wx.h>

#include "lsMainFrame.h"

class lsApp : public wxApp
{
public:
	bool OnInit() override
	{
		lsMainFrame* frame = new lsMainFrame();
        wxIcon icon;
        icon.LoadFile("../resources/images/icons/app.ico", wxBITMAP_TYPE_ICO);
        frame->SetIcon(icon);
        frame->SetAutoLayout(true);
		frame->Show();
		return true;
	}
};

wxIMPLEMENT_APP(lsApp);
