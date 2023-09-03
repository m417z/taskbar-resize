#include <windows.h>
#include <shlwapi.h>

void main()
{
    int argc;
    WCHAR **argv = CommandLineToArgvW(GetCommandLine(), &argc);

    if(argv)
    {
        if(argc >= 3)
        {
            BOOL bBottom = lstrcmpi(argv[1], L"-b") == 0;
            BOOL bTop = lstrcmpi(argv[1], L"-t") == 0;
            BOOL bRight = lstrcmpi(argv[1], L"-r") == 0;
            BOOL bLeft = lstrcmpi(argv[1], L"-l") == 0;
            int nMySize = StrToInt(argv[2]);

            HWND hTaskbarWnd = FindWindow(L"Shell_TrayWnd", NULL);
            if(hTaskbarWnd)
            {
                RECT rc;
                GetWindowRect(hTaskbarWnd, &rc);

                if(bBottom) {
                    rc.top = rc.bottom - nMySize;
                    SendMessage(hTaskbarWnd, WM_SIZING, WMSZ_TOP, (LPARAM)&rc);
                    SetWindowPos(hTaskbarWnd, NULL, 0, 0, rc.right - rc.left, nMySize, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
                }
                else if(bTop) {
                    rc.bottom = rc.top + nMySize;
                    SendMessage(hTaskbarWnd, WM_SIZING, WMSZ_BOTTOM, (LPARAM)&rc);
                    SetWindowPos(hTaskbarWnd, NULL, 0, 0, rc.right - rc.left, nMySize, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
                }
                else if(bRight) {
                    rc.left = rc.right - nMySize;
                    SendMessage(hTaskbarWnd, WM_SIZING, WMSZ_LEFT, (LPARAM)&rc);
                    SetWindowPos(hTaskbarWnd, NULL, 0, 0, nMySize, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
                }
                else if(bLeft) {
                    rc.right = rc.left + nMySize;
                    SendMessage(hTaskbarWnd, WM_SIZING, WMSZ_RIGHT, (LPARAM)&rc);
                    SetWindowPos(hTaskbarWnd, NULL, 0, 0, nMySize, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
                }
            }
        }

        LocalFree(argv);
    }

    ExitProcess(0);
}
