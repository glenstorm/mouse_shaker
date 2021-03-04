#include "mtaskbaricon.h"
#include <wx/artprov.h>
#include <wx/uiaction.h>

wxBEGIN_EVENT_TABLE(mTaskBarIcon, wxTaskBarIcon)
	EVT_TASKBAR_RIGHT_DOWN(mTaskBarIcon::OnTaskBarClick)
wxEND_EVENT_TABLE()

enum MenuIds
{
	switcher = 1,
};

mTaskBarIcon::mTaskBarIcon( wxTaskBarIconType iconType )
		: wxTaskBarIcon( iconType )
		, isTurnOn( true )
{
	mMenu = new wxMenu();
	mMenu->Append( switcher, wxString( wxT( "Включено" ) ),
							 wxString( wxT( "Включить или выключить" ) ),
							 wxITEM_CHECK );
	SetIcon( wxArtProvider::GetIcon( wxART_CROSS_MARK ) );
	m_timer.Bind( wxEVT_TIMER, &mTaskBarIcon::OnTimer, this );

	SwitchShakeProcess( isTurnOn );
}

void mTaskBarIcon::OnTimer( wxTimerEvent& event)
{
#if wxUSE_UIACTIONSIMULATOR

	wxMessageOutput::Get()->Printf("Hello!");
	wxUIActionSimulator sim;
	sim.MouseMove(wxGetMousePosition() + wxPoint(10, 10));
	sleep(1);
	sim.MouseMove(wxGetMousePosition() - wxPoint(10, 10));
	wxYield();

#endif
	event.Skip();
}

wxMenu* mTaskBarIcon::GetPopupMenu()
{
	return mMenu;
}

void mTaskBarIcon::OnTaskBarClick( wxTaskBarIconEvent& event )
{
	event.Skip();
}

void mTaskBarIcon::SwitchShakeProcess( bool val )
{
	isTurnOn = val;
	if( isTurnOn )
	{
		m_timer.Start( timerInterval );
	}
	else
	{
		m_timer.Stop();
	}

	mMenu->Check( switcher, isTurnOn );
}

mTaskBarIcon::~mTaskBarIcon()
{
	delete mMenu;
}
