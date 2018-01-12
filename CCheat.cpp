#include "stdafx.h"

ID3D11Device *CCheat::pDevice = NULL;
ID3D11DeviceContext *CCheat::pContext = NULL;
IDXGISwapChain* CCheat::pSwapChain = NULL;
ID3D11RenderTargetView* CCheat::pRenderTargetView = NULL;

void CCheat::Initialise()
{
	AllocConsole();
	freopen("CON", "w", stdout);
	SetConsoleTitleA("Project Frost");

	Helpers::Log("Cheat Initialised");
	Helpers::Log("Source by: SMBB");

	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

	HWND hWindow = FindWindowA(NULL, "Rainbow Six");

#pragma region Initialise DXGI_SWAP_CHAIN_DESC
	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(scd));

	// Help yourself: https://msdn.microsoft.com/en-us/library/windows/desktop/bb173076(v=vs.85).aspx
	scd.BufferCount = 1;
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; 
	scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; 
	scd.OutputWindow = hWindow; 
	scd.SampleDesc.Count = 1; 
	scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; 
	scd.Windowed = ((GetWindowLongPtr(hWindow, GWL_STYLE) & WS_POPUP) != 0) ? false : true; 
	scd.BufferDesc.Width = 1920; // temporary width
	scd.BufferDesc.Height = 1080; // temporary height
	scd.BufferDesc.RefreshRate.Numerator = 60; 
	scd.BufferDesc.RefreshRate.Denominator = 1; 
#pragma endregion

	if (FAILED(D3D11CreateDeviceAndSwapChain(
		NULL, D3D_DRIVER_TYPE_HARDWARE, NULL,
		NULL, &featureLevel, 1, D3D11_SDK_VERSION,
		&scd, &CCheat::pSwapChain,
		&CCheat::pDevice, NULL, &CCheat::pContext
	)))
	{
		Helpers::LogError("D3D11CreateDevice");
		return;
	}

	// Obtain vtable pointers
	DWORD_PTR*  pSwapChainVT = reinterpret_cast<DWORD_PTR*>(CCheat::pSwapChain);
	DWORD_PTR*  pDeviceVT = reinterpret_cast<DWORD_PTR*>(CCheat::pDevice);
	DWORD_PTR*  pContextVT = reinterpret_cast<DWORD_PTR*>(CCheat::pContext);

	pSwapChainVT = reinterpret_cast<DWORD_PTR*>(pSwapChainVT[0]);
	pDeviceVT = reinterpret_cast<DWORD_PTR*>(pDeviceVT[0]);
	pContextVT = reinterpret_cast<DWORD_PTR*>(pContextVT[0]);

	// Init our stuff
	Renderer::GetInstance()->Initialize();
	UserInterface::GetInstance()->SetStyle();
	Input::GetInstance()->StartThread();

	// obtain the functions
	Hooks::oPresent = reinterpret_cast<tD3D11Present>(pSwapChainVT[8]/*D3D11PRESENT*/);

	// hook our function
	Helpers::HookFunction(reinterpret_cast<PVOID*>(&Hooks::oPresent), Hooks::hkD3D11Present);
}

void CCheat::Release()
{
	// destory le console
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	FreeConsole();

	// Stop our stuff
	Input::GetInstance()->StopThread();

	// unhook our functions
	Helpers::UnhookFunction(reinterpret_cast<PVOID*>(&Hooks::oPresent), Hooks::hkD3D11Present);
}

void CCheat::GetResolution(UINT horizontal, UINT vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = FindWindowA(NULL, "Rainbow Six");
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

