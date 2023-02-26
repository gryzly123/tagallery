#pragma once
#include <wx/wx.h>
#include "wx/aui/framemanager.h"

class wxAuiNotebook;
//class wxAuiManager;

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
	void OnExit(wxCommandEvent& event);
	void OnOpenGallery(wxCommandEvent& event);
	void OnCloseGallery(wxCommandEvent& event);
	void OnCloseAll(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();

	void BuildMenuBar();

	wxAuiManager m_frameMgr;
	wxAuiNotebook* m_tabs;
};

enum
{
	ID_Hello = 1
};
