#include "GalleryWindow.hpp"

#include "wx/listctrl.h"
#include "wx/grid.h"
#include "wx/sizer.h"
#include "wx/splitter.h"
#include "wx/artprov.h"
#include "wx/dir.h"

GalleryWindow::GalleryWindow(wxWindow* parent, wxWindowID id)
	: wxWindow(parent, id)
{
	auto* vbox = new wxBoxSizer(wxVERTICAL);
	auto* hbox = new wxSplitterWindow(this);

	m_searchBar = new wxTextCtrl(this, wxID_ANY);
	vbox->Add(m_searchBar, 0, wxEXPAND | wxALL, 5);

	wxImageList* iconList = new wxImageList(16, 16);
	wxBitmap bitmap = wxArtProvider::GetBitmap(wxART_FOLDER, wxART_LIST);
	iconList->Add(bitmap);
	bitmap = wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_LIST);
	iconList->Add(bitmap);

	m_tagList = new wxListCtrl(hbox, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_SMALL_ICON | wxLC_SINGLE_SEL);
	m_tagList->SetImageList(iconList, wxIMAGE_LIST_SMALL);
	for (size_t i = 0; i < 100; ++i)
	{
		wxListItem item;
		item.SetId(i);
		item.SetImage(i%2);
		item.SetText("Tag name (123)");
		m_tagList->InsertItem(item);
	}

	m_thumbs = new wxListCtrl(hbox, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON);
	wxImageList* imageList2 = new wxImageList(128, 128);
	wxString dirPath = wxT("memes");
	wxDir dir(dirPath);
	if (dir.IsOpened())
	{
		wxString fileName;
		bool cont = dir.GetFirst(&fileName, wxEmptyString, wxDIR_FILES);
		while (cont)
		{
			wxImage image(dirPath + wxT("/") + fileName);
			wxBitmap bitmap(image.Scale(128, 128, wxIMAGE_QUALITY_BICUBIC));
			imageList2->Add(bitmap);
			cont = dir.GetNext(&fileName);
		}
	}

	m_thumbs->AssignImageList(imageList2, wxIMAGE_LIST_NORMAL);

	wxString fileName;
	bool cont = dir.GetFirst(&fileName, wxEmptyString, wxDIR_FILES);
	int index = 0;
	while (cont)
	{
		wxListItem listItem;
		listItem.SetId(index);
		listItem.SetColumn(0);
		listItem.SetMask(wxLIST_MASK_TEXT | wxLIST_MASK_IMAGE | wxLIST_MASK_DATA);
		listItem.SetText(fileName);
		listItem.SetImage(index);
		listItem.SetData(index);
		m_thumbs->InsertItem(listItem);
		index++;
		cont = dir.GetNext(&fileName);
	}

	m_thumbs->Bind(wxEVT_SIZE, [this](wxSizeEvent& event) {
		m_thumbs->Arrange(wxLIST_ALIGN_TOP);
	});

	hbox->SplitVertically(m_tagList, m_thumbs, 200);
	vbox->Add(hbox, 2, wxEXPAND | wxALL, 5);

	SetSizer(vbox);
}
