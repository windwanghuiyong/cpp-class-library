#include <windows.h>
#include "resource.h"		// resource IDs
#include "generic.h"

HINSTANCE	_hInst;		// Instance handle
HWND			_hWnd;

char _szAppName[] = "Generic";						// ��������
char _szTitle[]   = "Generic Sample Application";	// ���ڱ���

/*********************************
	WinMain windows ��������
*********************************/
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;

	/* �������ʱ�ľ��� */
	UNREFERENCED_PARAMETER(lpCmdLine);
	
	/* �������ע��, ֻ�иó���ĵ�1��ʵ���Ż���� */
	if (!hPreInstance)								// ��ֵ��ϵͳ����, win32ϵͳ�У���ֵ��ԶΪ0, ���ÿ��ʵ���������
		if (!InitApplication(hInstance))
			return FALSE;
	
	/* ���ڵĲ��� */
	if (!InitInstance(hInstance, nCmdShow))
		return FALSE;
	
	/* ��Ϣѭ�� */
	while (GetMessage(&msg, NULL, 0, 0))	// �߱�����������
	{
		TranslateMessage(&msg);		// ת��������Ϣ
		DispatchMessage(&msg);		// ������Ϣ�����ں���	
	}

	return (msg.wParam);			// ���� PostQuitMessage ����
}

/*********************************
	InitApplication ע�ᴰ����
*********************************/
BOOL InitApplication(HINSTANCE hInstance)
{
	/* ������ */
	WNDCLASS wc;

	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = (WNDPROC)WndProc;					// ָ�����ں���(���ڽ��յ���Ϣ����Ϊ)
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(hInstance, "jjhouricon");
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = GetSockObject(WHITE_BRUSH);			// ���ں�̨��ɫ
	wc.lpszMenuName  = "GenericMenu";						// .RC ������Ĵ���
	wc.lpszClassName = _szAppName;

	return (RegisterClass(&wc));							// �趨��������
}

/******************************
	InitInstance ��������
		�κ�ʵ���������
		��������
		��ʾ����
		���ƴ���
******************************/
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	_hInst = hInstance;		// ȫ�ֱ���
	_hWnd  = CreateWindow {				// ��������
				_szAppName,
				_szTitle,
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				NULL,
				NULL,
				hInstance,
				NULL
	};

	if (!_hWnd)
		return FALSE;

	ShowWindow(_hWnd, nCmdShow);		// ��ʾ����
	UpdateWindow(_hWnd);				// �ͳ� WM_PAINT �������ڵĻ�ͼ����
	return TRUE;
}

/******************************
	WndProc ���ں���
		��ϵͳ����
******************************/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wnEvent;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(_hInst, "AboutBox", hWnd, (DLGPROC)About);	//	�Ի�����Դ���ƣ������ڣ��Ի���������
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return (DefWindowProc(hWnd, message, wParam, lParam));
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hWnd, message, wParam, lParam));	// ϵͳĬ�ϵ���Ϣ������
	}
	return 0;
}

/*************************
	About �Ի�����
*************************/
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCALCEL)
		{
			EndDialog(hDlg, TRUE);
			return TRUE;
		}
		break;
	}
	return FALSE;
}