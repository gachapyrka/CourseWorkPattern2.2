
// Pattern.cpp: îïðåäåëÿåò ïîâåäåíèå êëàññîâ äëÿ ïðèëîæåíèÿ.
//

#include "pch.h"
#include "framework.h"
#include "Pattern.h"
#include "PatternDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPatternApp

BEGIN_MESSAGE_MAP(CPatternApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Ñîçäàíèå CPatternApp

CPatternApp::CPatternApp()
{
	// ïîääåðæêà äèñïåò÷åðà ïåðåçàãðóçêè
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: äîáàâüòå êîä ñîçäàíèÿ,
	// Ðàçìåùàåò âåñü âàæíûé êîä èíèöèàëèçàöèè â InitInstance
}


// Åäèíñòâåííûé îáúåêò CPatternApp

CPatternApp theApp;


// Èíèöèàëèçàöèÿ CPatternApp

BOOL CPatternApp::InitInstance()
{
	// InitCommonControlsEx() òðåáóåòñÿ äëÿ Windows XP, åñëè ìàíèôåñò
	// ïðèëîæåíèÿ èñïîëüçóåò ComCtl32.dll âåðñèè 6 èëè áîëåå ïîçäíåé âåðñèè äëÿ âêëþ÷åíèÿ
	// ñòèëåé îòîáðàæåíèÿ.  Â ïðîòèâíîì ñëó÷àå áóäåò âîçíèêàòü ñáîé ïðè ñîçäàíèè ëþáîãî îêíà.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Âûáåðèòå ýòîò ïàðàìåòð äëÿ âêëþ÷åíèÿ âñåõ îáùèõ êëàññîâ óïðàâëåíèÿ, êîòîðûå íåîáõîäèìî èñïîëüçîâàòü
	// â âàøåì ïðèëîæåíèè.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Ñîçäàòü äèñïåò÷åð îáîëî÷êè, â ñëó÷àå, åñëè äèàëîãîâîå îêíî ñîäåðæèò
	// ïðåäñòàâëåíèå äåðåâà îáîëî÷êè èëè êàêèå-ëèáî åãî ýëåìåíòû óïðàâëåíèÿ.
	CShellManager *pShellManager = new CShellManager;

	// Àêòèâàöèÿ âèçóàëüíîãî äèñïåò÷åðà "Êëàññè÷åñêèé Windows" äëÿ âêëþ÷åíèÿ ýëåìåíòîâ óïðàâëåíèÿ MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Ñòàíäàðòíàÿ èíèöèàëèçàöèÿ
	// Åñëè ýòè âîçìîæíîñòè íå èñïîëüçóþòñÿ è íåîáõîäèìî óìåíüøèòü ðàçìåð
	// êîíå÷íîãî èñïîëíÿåìîãî ôàéëà, íåîáõîäèìî óäàëèòü èç ñëåäóþùèõ
	// êîíêðåòíûõ ïðîöåäóð èíèöèàëèçàöèè, êîòîðûå íå òðåáóþòñÿ
	// Èçìåíèòå ðàçäåë ðååñòðà, â êîòîðîì õðàíÿòñÿ ïàðàìåòðû
	// TODO: ñëåäóåò èçìåíèòü ýòó ñòðîêó íà ÷òî-íèáóäü ïîäõîäÿùåå,
	// íàïðèìåð íà íàçâàíèå îðãàíèçàöèè
	SetRegistryKey(_T("Ëîêàëüíûå ïðèëîæåíèÿ, ñîçäàííûå ñ ïîìîùüþ ìàñòåðà ïðèëîæåíèé"));

	CPatternDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Ââåäèòå êîä äëÿ îáðàáîòêè çàêðûòèÿ äèàëîãîâîãî îêíà
		//  ñ ïîìîùüþ êíîïêè "ÎÊ"
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Ââåäèòå êîä äëÿ îáðàáîòêè çàêðûòèÿ äèàëîãîâîãî îêíà
		//  ñ ïîìîùüþ êíîïêè "Îòìåíà"
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Ïðåäóïðåæäåíèå. Íå óäàëîñü ñîçäàòü äèàëîãîâîå îêíî, ïîýòîìó ðàáîòà ïðèëîæåíèÿ íåîæèäàííî çàâåðøåíà.\n");
		TRACE(traceAppMsg, 0, "Ïðåäóïðåæäåíèå. Ïðè èñïîëüçîâàíèè ýëåìåíòîâ óïðàâëåíèÿ MFC äëÿ äèàëîãîâîãî îêíà íåâîçìîæíî #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Óäàëèòü äèñïåò÷åð îáîëî÷êè, ñîçäàííûé âûøå.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Ïîñêîëüêó äèàëîãîâîå îêíî çàêðûòî, âîçâðàòèòå çíà÷åíèå FALSE, ÷òîáû ìîæíî áûëî âûéòè èç
	//  ïðèëîæåíèÿ âìåñòî çàïóñêà ãåíåðàòîðà ñîîáùåíèé ïðèëîæåíèÿ.
	return FALSE;
}

