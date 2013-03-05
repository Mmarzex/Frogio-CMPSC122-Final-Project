#ifndef _H_COREFORAPP
#define _H_COREFORAPP

// interpreter header
#include "template.h"

#ifdef IDE_MEEGO
// need access to main app ptr
extern QApplication* g_appptr;
#endif

int AppInitCode ( void )
{
	App.m_DeviceWidth = 1024;
	App.m_DeviceHeight = 768;
	return 1;
}

void AppGatherData ( DWORD dwhWnd, char* lpCmdLine )
{
}

void AppForceExit ( void )
{
	// completely exit the app
	#ifdef AGKWINDOWS
	PostQuitMessage(0);
	#endif
	#ifdef AGKIOS
	// forcing a quit in iOS is against recommended guidelines - use HOME button
	// the exit button is disabled on AGKIOS builds
	#endif
    #ifdef IDE_MEEGO
    g_appptr->quit();
    #endif
	#ifdef IDE_MAC
	glfwCloseWindow();
	#endif
	#ifdef IDE_BADA
	// Bada platform has a HOME button to quit apps
	#endif
}

#endif // _H_COREFORAPP

