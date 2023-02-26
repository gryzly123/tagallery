#include "Application.hpp"
#include "MainFrame.hpp"

bool TagalleryApp::OnInit()
{
	if (!GetTraits())
	{
		wxFAIL_MSG("No traits");
	}
	MainFrame *frame = new MainFrame("Tagallery", wxPoint(50, 50), wxSize(760, 560));
	frame->Show(true);
	return true;
}
