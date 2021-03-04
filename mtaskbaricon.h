#ifndef _M_TASKBAR_ICON_H_GUARD_
#define _M_TASKBAR_ICON_H_GUARD_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/taskbar.h>


class mTaskBarIcon: public wxTaskBarIcon
{
public:
	mTaskBarIcon( wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE );
	virtual ~mTaskBarIcon();
private:
	///
	wxDECLARE_EVENT_TABLE();
	///
	void OnTaskBarClick( wxTaskBarIconEvent& event );
	///
	void SwitchShakeProcess( bool val );
	///
	wxMenu* mMenu;
	///
	bool isTurnOn;
	///
	wxTimer m_timer;
	///
	static const int timerInterval = 1000; // every minute
protected:
	///
	virtual wxMenu* GetPopupMenu();
	///
	void OnTimer( wxTimerEvent& );
};

#endif
