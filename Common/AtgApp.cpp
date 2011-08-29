//--------------------------------------------------------------------------------------
// AtgApp.cpp
//
// Application class for samples
//
// Xbox Advanced Technology Group.
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include "stdafx.h"
#include "AtgApp.h"
#include "AtgUtil.h"

// Ignore warning about "unused" pD3D variable
#pragma warning( disable: 4189 )

namespace ATG
{

//--------------------------------------------------------------------------------------
// Globals
//--------------------------------------------------------------------------------------

// Global access to the main D3D device
D3DDevice* g_pd3dDevice = NULL;

// Private access to the main D3D device
D3DDevice* Application::m_pd3dDevice = NULL;

// The device-creation presentation params with reasonable defaults
D3DPRESENT_PARAMETERS Application::m_d3dpp =
{
    1280,                // BackBufferWidth;
    720,                // BackBufferHeight;
    D3DFMT_A8R8G8B8,    // BackBufferFormat;
    1,                  // BackBufferCount;
    D3DMULTISAMPLE_NONE,// MultiSampleType;
    0,                  // MultiSampleQuality;
    D3DSWAPEFFECT_DISCARD, // SwapEffect;
    NULL,               // hDeviceWindow;
    FALSE,              // Windowed;
    TRUE,               // EnableAutoDepthStencil;
    D3DFMT_D24S8,       // AutoDepthStencilFormat;
    0,                  // Flags;
    0,                  // FullScreen_RefreshRateInHz;
    D3DPRESENT_INTERVAL_IMMEDIATE, // FullScreen_PresentationInterval;
};

void Application::SetD3DDevice(D3DDevice* device) {
	g_pd3dDevice = device;
}

// Extra flags to use at Direct3D device creation time
DWORD Application::m_dwDeviceCreationFlags = 0;

//--------------------------------------------------------------------------------------
// Name: Run()
// Desc: Creates the D3D device, calls Initialize() and enters an infinite loop
//       calling Update() and Render()
//--------------------------------------------------------------------------------------
VOID Application::Run()
{
    HRESULT hr;

    //LPDIRECT3D9 pD3D = Direct3DCreate9( D3D_SDK_VERSION );

   
    //pD3D->Release();

    // Allow global access to the device
    m_pd3dDevice = g_pd3dDevice;

    // Initialize the app's device-dependent objects
    if( FAILED( hr = Initialize() ) )
    {
        ATG_PrintError( "Call to Initialize() failed!\n" );
        DebugBreak();
    }

    // Run the game loop
    for(; ; )
    {
        // Update the scene
        Update();

        // Render the scene
        Render();
    }
}

} // namespace ATG