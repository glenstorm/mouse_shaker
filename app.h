#ifndef _APP_H_GUARD_
#define _APP_H_GUARD_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MyApp: public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP( MyApp );

#endif
