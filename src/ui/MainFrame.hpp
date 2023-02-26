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

	wxAuiNotebook* m_tabs;

	wxAuiManager m_frameMgr;
	wxBoxSizer* m_vbox;
};

enum
{
	ID_Hello = 1
};
