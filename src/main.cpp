/*
#include "engine/Engine.hpp"

#include "wx/wx.h"

enum
{
	ID_Hello = 1
};

class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	{
		wxMenu *menuFile = new wxMenu;
		menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
			"Help string shown in status bar for this menu item");
		menuFile->AppendSeparator();
		menuFile->Append(wxID_EXIT);
		wxMenu *menuHelp = new wxMenu;
		menuHelp->Append(wxID_ABOUT);
		wxMenuBar *menuBar = new wxMenuBar;
		menuBar->Append(menuFile, "&File");
		menuBar->Append(menuHelp, "&Help");
		SetMenuBar(menuBar);
		CreateStatusBar();
		SetStatusText("Welcome to wxWidgets!");
	}
private:
	void OnHello(wxCommandEvent& event)
	{
		wxLogMessage("Hello world from wxWidgets!");
	}

	void OnExit(wxCommandEvent& event)
	{
		Close(true);
	}

	void OnAbout(wxCommandEvent& event)
	{
		wxMessageBox("This is a wxWidgets' Hello world sample",
			"About Hello World", wxOK | wxICON_INFORMATION);
	}

	wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_Hello, MyFrame::OnHello)
	EVT_MENU(wxID_EXIT, MyFrame::OnExit)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

class TagalleryApp : public wxApp
{
public:
	virtual bool OnInit()
	{
		tagallery::Engine e("foo/bar");

		MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
		frame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(TagalleryApp);

int main()
{
	tagallery::Engine e( "foo/bar" );
	return 1;
}
*/

#include "ui/Application.hpp"
wxIMPLEMENT_APP( TagalleryApp );


