#include "TagListView.hpp"

namespace tagallery
{
	TagListCtrl::TagListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
		: wxListCtrl(parent, id, pos, size, wxLC_SMALL_ICON | wxLC_SINGLE_SEL | wxLC_HRULES)
	{
		Bind(wxEVT_PAINT, &TagListCtrl::OnPaint, this);
	}

	void TagListCtrl::OnPaint(wxPaintEvent& event)
	{
		wxListCtrl::OnPaint(event);

		wxListItem item;
		item.SetMask(wxLIST_MASK_STATE);
		item.SetState(wxLIST_STATE_SELECTED);

		wxPaintDC dc(this);
		dc.SetBrush(wxBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT)));
		dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT)));
		
		int count = GetItemCount();
		for (int i = 0; i < count; i++)
		{
			item.SetId(i);
			GetItem(item);
			if (item.GetState() & wxLIST_STATE_SELECTED)
			{
				wxRect rect;
				if (GetItemRect(i, rect))
				{
					rect.width *= 4;
					dc.DrawRectangle(rect);
				}
				break;
			}
		}
	}
}
