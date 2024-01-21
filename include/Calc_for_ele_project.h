
// Calc_for_ele_project.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCalcforeleprojectApp:
// See Calc_for_ele_project.cpp for the implementation of this class
//

class CCalcforeleprojectApp : public CWinApp
{
public:
	CCalcforeleprojectApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCalcforeleprojectApp theApp;
