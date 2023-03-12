#include "Application.hpp"
#include "MainFrame.hpp"

#include "../engine/Engine.hpp"

bool TagalleryApp::OnInit()
{
	if (!GetTraits())
	{
		wxFAIL_MSG("No traits");
	}

	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxPNGHandler);

	tagallery::Engine e;
	e.OpenGallery("memes", true);


	MainFrame *frame = new MainFrame("Tagallery", wxPoint(50, 50), wxSize(760, 560));
	frame->Show(true);
	return true;
}
