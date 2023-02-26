#include "GalleryWindow.hpp"

#include "wx/htmllbox.h"
#include "wx/grid.h"
#include "wx/sizer.h"
#include "wx/splitter.h"

GalleryWindow::GalleryWindow(wxWindow* parent, wxWindowID id)
	: wxWindow(parent, id)
{
	auto* vbox = new wxBoxSizer(wxVERTICAL);
	auto* hbox = new wxSplitterWindow(this);

	m_searchBar = new wxTextCtrl(this, wxID_ANY);
	vbox->Add(m_searchBar, 0, wxEXPAND | wxALL, 5);

	m_tagList = new wxSimpleHtmlListBox(hbox, wxID_ANY);
	std::vector<wxString> tags( (size_t)200, "<b>Tag name</b> <i>123</i>" );
	m_tagList->Append(tags);

	m_thumbs = new wxGrid(hbox, wxID_ANY);
	m_thumbs->CreateGrid(5, 5);

	hbox->SplitVertically(m_tagList, m_thumbs, 200);
	vbox->Add(hbox, 2, wxEXPAND | wxALL, 5);

	SetSizer(vbox);
}
