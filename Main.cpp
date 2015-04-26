#include <iostream>
#include <string>

#include <Windows.h>
#include <tchar.h>
#include <psapi.h>

bool IsCurrentWindowBlank(HWND handle) {
	// I'm trying to find out what we can do to programatically decide
	// if there's a UAC prompt running
	int bufsize = GetWindowTextLength(handle) + 1;
	LPWSTR title = new WCHAR[bufsize];
	GetWindowText(handle, title, bufsize);
	DWORD pid = 0;
	GetWindowThreadProcessId(handle, &pid);
	if ((lstrlenW(title) == 0) && (pid == 0)) {
		return true;
	}
	else {
		std::wcout << title << " " << pid << std::endl;
		return false;
	}

	//std::wcout << title << " " << pid << std::endl;
}

int main() {
	// my current thinking is that if the window is blank,
	// it might be a UAC prompt
	DWORD pid = 0;
	DWORD old_pid = 0;
	while (1) {
		HWND handle = GetForegroundWindow();
		GetWindowThreadProcessId(handle, &pid);
		
		// if we don't do this, we'll loop and check every ms
		if (pid != old_pid) {
			if (IsCurrentWindowBlank(handle)) {
				std::wcout << "Current window is blank" << std::endl;
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