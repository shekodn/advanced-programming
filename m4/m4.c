#define _WIN32_WINNT 0x0400
#pragma comment( lib, "user32.lib" )

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

HHOOK hMouseHook;

char cCoords[100];

LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    MOUSEHOOKSTRUCT * pMouseStruct = (MOUSEHOOKSTRUCT *)lParam;
    if (pMouseStruct != NULL)
	{
        if(wParam == WM_LBUTTONDOWN)
        {
		    FILE *fp;
			fp = fopen ( "coordinates.txt", "a+t" );

			sprintf(cCoords, "Mouse position X: %i Mouse position Y: %i \n", pMouseStruct->pt.x, pMouseStruct->pt.y);
			fputs(cCoords, fp);

			fclose(fp);
        }
    }
    return CallNextHookEx(hMouseHook, nCode, wParam, lParam);
}

DWORD WINAPI MyMouseLogger(LPVOID lpParm)
{
    HINSTANCE hInstance = GetModuleHandle(NULL);

    hMouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, hInstance, NULL);

    MSG message;
    while(GetMessage(&message,NULL,0,0))
	{
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    UnhookWindowsHookEx(hMouseHook);
    return 0;
}

int main(int argc, char** argv)
{
    HANDLE hThread;
    DWORD dwThread;

    hThread = CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)MyMouseLogger, (LPVOID) argv[0], NULL, &dwThread);
    if (hThread)
        return WaitForSingleObject(hThread,INFINITE);
    else
        return 1;
}
