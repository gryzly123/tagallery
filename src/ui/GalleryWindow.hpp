#pragma once
#include <wx/wx.h>
#include "TagListView.hpp"

class wxTextCtrl;
class wxListCtrl;
class wxGrid;

class GalleryWindow : public wxWindow
{
public:
	GalleryWindow(wxWindow* parent, wxWindowID id = wxID_ANY);

private:
	wxTextCtrl* m_searchBar;
	wxListCtrl* m_tagList;
	wxListCtrl* m_thumbs;
};
