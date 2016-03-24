#ifndef __SRW_ENGINE_RHI_PLATFORM_DEFINE_DX11_H___
#define __SRW_ENGINE_RHI_PLATFORM_DEFINE_DX11_H___

#include <d3d11.h>
#include <d3dx11.h>

// use the correct format depending on the target platform
#ifdef PLATFORM_DURANGO
#define DX11_IID_PPV_ARGS IID_GRAPHICS_PPV_ARGS
typedef DXGI_SWAP_CHAIN_DESC1	SWAP_CHAIN_DESC;
typedef IDXGISwapChain1			DXGISwapChain;
#else
#define DX11_IID_PPV_ARGS IID_PPV_ARGS

typedef DXGI_SWAP_CHAIN_DESC	SWAP_CHAIN_DESC;
typedef IDXGISwapChain			DXGISwapChain;

#endif




#endif