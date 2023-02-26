#include "wx/wx.h"
#include "wx/listctrl.h"

namespace tagallery
{
	class TagListCtrl : public wxListCtrl
	{
	public:
		TagListCtrl(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);

	protected:
		void OnPaint(wxPaintEvent& event);
	};
}
