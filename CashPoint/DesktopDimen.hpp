#include <Windows.h>

class DesktopWindow
{
public:
	int GetDesktopLength()
	{
		RECT Desk;
		const HWND hDesk = GetDesktopWindow();
		GetWindowRect(hDesk, &Desk);
		int Length = Desk.right;
		return Length;
	}
	int GetDesktopHeight()
	{
		RECT Desk;
		const HWND hDesk = GetDesktopWindow();
		GetWindowRect(hDesk, &Desk);
		int Height = Desk.bottom;
		return Height;
	}
};