
// Because the SendInput function is only supported in
// Windows 2000 and later, WINVER needs to be set as
// follows so that SendInput gets defined when windows.h
// is included below.
#define WINVER 0x0500
#include <windows.h>
#include <iostream>

int main()
{
	INPUT ip;
	bool ShouldAuto = false;

	ip.type = INPUT_MOUSE;
	ip.mi.time = 0;
	ip.mi.dwExtraInfo = 0;
	ip.mi.dx = 0;
	ip.mi.dy = 0;
	while (1)
	{
		if (GetAsyncKeyState(VK_MBUTTON))
		{
			//std::cout << "Shoot!";

			ip.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_MOVE;
			SendInput(1, &ip, sizeof(INPUT));

			ip.mi.dwFlags = MOUSEEVENTF_LEFTUP | MOUSEEVENTF_MOVE;
			SendInput(1, &ip, sizeof(INPUT));

			Sleep(30);
		}
	}
	return 0;
}
