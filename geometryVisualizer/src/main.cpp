#include <wx/wx.h>

#include "lsMainFrame.h"

class lsApp : public wxApp
{
public:
	bool OnInit() override
	{
		lsMainFrame* frame = new lsMainFrame();
		frame->Show();
		return true;
	}
};

wxIMPLEMENT_APP(lsApp);
