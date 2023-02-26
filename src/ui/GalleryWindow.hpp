#pragma once
#include <wx/wx.h>
#include "TagListView.hpp"

class wxTextCtrl;
class wxSimpleHtmlListBox;
class wxGrid;

class GalleryWindow : public wxWindow
{
public:
	GalleryWindow(wxWindow* parent, wxWindowID id = wxID_ANY);

private:
	wxTextCtrl* m_searchBar;
	wxSimpleHtmlListBox* m_tagList;
	wxGrid* m_thumbs;
};
