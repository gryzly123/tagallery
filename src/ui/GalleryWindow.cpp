#include "GalleryWindow.hpp"

#include "wx/listctrl.h"
#include "wx/grid.h"
#include "wx/sizer.h"
#include "wx/splitter.h"
#include "wx/artprov.h"

GalleryWindow::GalleryWindow(wxWindow* parent, wxWindowID id)
	: wxWindow(parent, id)
{
	auto* vbox = new wxBoxSizer(wxVERTICAL);
	auto* hbox = new wxSplitterWindow(this);

	m_searchBar = new wxTextCtrl(this, wxID_ANY);
	vbox->Add(m_searchBar, 0, wxEXPAND | wxALL, 5);

	wxImageList* imageList = new wxImageList(16, 16);
	wxBitmap bitmap = wxArtProvider::GetBitmap(wxART_FOLDER, wxART_LIST);
	imageList->Add(bitmap);
	bitmap = wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_LIST);
	imageList->Add(bitmap);

	m_tagList = new wxListCtrl(hbox, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_SMALL_ICON | wxLC_SINGLE_SEL);
	m_tagList->SetImageList(imageList, wxIMAGE_LIST_SMALL);
	for (size_t i = 0; i < 100; ++i)
	{
		wxListItem item;
		item.SetId(i);
		item.SetImage(i%2);
		item.SetText("Tag name (123)");
		m_tagList->InsertItem(item);
	}

	m_thumbs = new wxGrid(hbox, wxID_ANY);
	m_thumbs->CreateGrid(5, 5);

	hbox->SplitVertically(m_tagList, m_thumbs, 200);
	vbox->Add(hbox, 2, wxEXPAND | wxALL, 5);

	SetSizer(vbox);
}
