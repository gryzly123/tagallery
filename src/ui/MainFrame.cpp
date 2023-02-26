#include "MainFrame.hpp"
#include "GalleryWindow.hpp"

#include "wx/aui/auibook.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
  EVT_MENU(wxID_OPEN, MainFrame::OnOpenGallery)
  EVT_MENU(wxID_CLOSE, MainFrame::OnCloseGallery)
  EVT_MENU(wxID_CLOSE_ALL, MainFrame::OnCloseAll)
  EVT_MENU(wxID_EXIT, MainFrame::OnExit)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	m_frameMgr.SetManagedWindow(this);
	BuildMenuBar();

	m_vbox = new wxBoxSizer(wxVERTICAL);
	SetSizer(m_vbox);


	//m_tabs = new wxAuiNotebook( this, -1, wxDefaultPosition, wxDefaultSize );
	//m_tabs->DragAcceptFiles(true);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
	m_frameMgr.UnInit();
	Close( true );
}

void MainFrame::OnOpenGallery(wxCommandEvent & event)
{
	static int pageId = 0;
	++pageId;

	auto* gallery = new GalleryWindow(this);
	m_vbox->Add(gallery, 1, wxEXPAND | wxALL, 5);
	Layout();

	//auto* vbox = new wxBoxSizer(wxVERTICAL);
	//auto* gallery = new GalleryWindow(this);
	//vbox->Add(gallery, 1, wxEXPAND | wxALL, 5);
	//SetSizer(vbox);

	//m_tabs->AddPage(new wxWindow, wxString::Format(wxT("Tab #%i"), pageId ), true);
	//auto* page = m_tabs->GetPage(pageId);
	//auto* window = new GalleryWindow(page);
}

void MainFrame::OnCloseGallery(wxCommandEvent & event)
{
}

void MainFrame::OnCloseAll(wxCommandEvent & event)
{
}

void MainFrame::BuildMenuBar()
{
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(wxID_OPEN, "&Open gallery");
	menuFile->Append(wxID_CLOSE, "&Close gallery");
	menuFile->Append(wxID_CLOSE_ALL, "&Close all");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenuBar* menuBar = new wxMenuBar();
	menuBar->Append(menuFile, "&File");
	SetMenuBar(menuBar);
}
