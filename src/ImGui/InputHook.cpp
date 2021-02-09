#include "InputHook.h"
#include <iostream>
#include "ZInputActionManager.h"
#include "BaseAddresses.h"

using namespace ImGui;

WNDPROC	oWndProc;

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void InputHook::Init(HWND hWindow)
{
	oWndProc = (WNDPROC)SetWindowLongPtr(hWindow, GWLP_WNDPROC, (__int3264)(LONG_PTR)WndProc);
}

void InputHook::Remove(HWND hWindow)
{
	SetWindowLongPtr(hWindow, GWLP_WNDPROC, (LONG_PTR)oWndProc);
}

LRESULT APIENTRY WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ImGuiIO& io = ImGui::GetIO();

	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
		io.MouseDown[0] = true; return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	case WM_LBUTTONUP:
		io.MouseDown[0] = false; return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	case WM_RBUTTONDOWN:
		io.MouseDown[1] = true; return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	case WM_RBUTTONUP:
		io.MouseDown[1] = false; return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	case WM_MBUTTONDOWN:
		io.MouseDown[2] = true; return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	case WM_MBUTTONUP:
		io.MouseDown[2] = false; return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	case WM_MOUSEWHEEL:
		io.MouseWheel += GET_WHEEL_DELTA_WPARAM(wParam) > 0 ? +1.0f : -1.0f; return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	case WM_MOUSEMOVE:
		io.MousePos.x = (signed short)(lParam); io.MousePos.y = (signed short)(lParam >> 16); return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		if (wParam < 256)
			io.KeysDown[wParam] = 1;
		return 0;
	case WM_KEYUP:
	case WM_SYSKEYUP:
		if (wParam < 256)
			io.KeysDown[wParam] = 0;
		return 0;
	case WM_CHAR:
		// You can also use ToAscii()+GetKeyboardState() to retrieve characters.
		if (wParam > 0 && wParam < 0x10000)
			io.AddInputCharacterUTF16((unsigned short)wParam);
		return 0;
	case WM_SETFOCUS:
		std::fill_n(io.KeysDown, 512, 0);
		return 0;
	}

	return CallWindowProc(oWndProc, hwnd, uMsg, wParam, lParam);
}
