#include <windows.h>
#include <shlwapi.h>
#include "buffer.h"

void main()
{
	int argc;
	WCHAR **argv = CommandLineToArgvW(GetCommandLine(), &argc);

	if(argv)
	{
		if(argc >= 3)
		{
			BOOL bRight = lstrcmpi(argv[1], L"-r") == 0;
			int nWidth = StrToInt(argv[2]);

			HWND hTaskbarWnd = FindWindow(L"Shell_TrayWnd", NULL);
			if(hTaskbarWnd)
			{
				RECT rc;
				GetWindowRect(hTaskbarWnd, &rc);

				if(bRight)
					rc.left = rc.right - nWidth;
				else
					rc.right = rc.left + nWidth;

				SendMessage(hTaskbarWnd, WM_SIZING, WMSZ_LEFT, (LPARAM)&rc);
				SetWindowPos(hTaskbarWnd, NULL, 0, 0, nWidth, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
			}
		}

		LocalFree(argv);
	}

	ExitProcess(0);
}
