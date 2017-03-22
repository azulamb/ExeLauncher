#include <Windows.h>

#define __EXE_PATH "notepad.exe"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	WCHAR EXE_PATH[] = TEXT( __EXE_PATH );
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFO si = { 0 };
	si.cb = sizeof(STARTUPINFO);

	int a = CreateProcess( NULL, EXE_PATH, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi );

	return 0;
}
