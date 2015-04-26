#include <iostream>
#include <string>

#include <Windows.h>
#include <tchar.h>
#include <psapi.h>

// Possibly find out what we can do to programatically decide if the current handle is a UAC prompt
bool IsCurrentWindowBlank(HWND handle) {
	int bufsize = GetWindowTextLength(handle) + 1;
	LPWSTR title = new WCHAR[bufsize];
	GetWindowText(handle, title, bufsize);
	DWORD pid = 0;
	GetWindowThreadProcessId(handle, &pid);
	if ((lstrlenW(title) == 0) && (pid == 0)) {
		return true;
	}
	return false;
}


int main() {
	DWORD pid = 0;
	DWORD old_pid = 0;
	while (1) {
		HWND handle = GetForegroundWindow();
		GetWindowThreadProcessId(handle, &pid);

		// confirm that this is a new window
		if (pid != old_pid) {
			if (IsCurrentWindowBlank(handle)) {
				std::wcout << handle << std::endl;
				// current window is blank, let's try to enter our keys
				Sleep(1000);
				SendMessage(handle, WM_KEYDOWN, (WPARAM)VK_LEFT, 1);
				SendMessage(handle, WM_KEYUP, 0, 0);
			}
		}

		Sleep(100);
		old_pid = pid;

		// pid needs to be reset to zero in case the pointer returns unused
		pid = 0;
	}
	return 0;
}