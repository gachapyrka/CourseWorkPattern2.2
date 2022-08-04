
// Pattern.h: ãëàâíûé ôàéë çàãîëîâêà äëÿ ïðèëîæåíèÿ PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "âêëþ÷èòü pch.h äî âêëþ÷åíèÿ ýòîãî ôàéëà â PCH"
#endif

#include "resource.h"		// îñíîâíûå ñèìâîëû


// CPatternApp:
// Ñâåäåíèÿ î ðåàëèçàöèè ýòîãî êëàññà: Pattern.cpp
//

class CPatternApp : public CWinApp
{
public:
	CPatternApp();

// Ïåðåîïðåäåëåíèå
public:
	virtual BOOL InitInstance();

// Ðåàëèçàöèÿ

	DECLARE_MESSAGE_MAP()
};

extern CPatternApp theApp;
