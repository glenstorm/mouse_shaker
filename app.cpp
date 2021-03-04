#include "app.h"
#include "mtaskbaricon.h"

bool MyApp::OnInit()
{
    mTaskBarIcon *tbIcon = new mTaskBarIcon();

	if( tbIcon->IsAvailable() )
	{
		if( tbIcon->IsOk() )
			wxMessageBox( wxT("Hello World!") );
		else
		{
			wxMessageBox( wxT("TaskBar is not ok!") );
			tbIcon->Destroy();
			return false;
		}
	}
	else
	{
		// wxMessageBox( wxT("TaskBar is not supported!") );
		// tbIcon->Destroy();
		// return false;
	}

	return true;
}
