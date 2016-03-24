#ifndef __SRW_ENGINE_RHI_SWAPCHAIN_DX11_H___
#define __SRW_ENGINE_RHI_SWAPCHAIN_DX11_H___

#include <windows.h>

#include "PlatformDefineDX11.h"
#include "SrwCore.h"


namespace SrwEngineRHI
{
	class GraphicDeviceDX11;
	class RenderWindowDX11;

	class SwapChainDX11
	{
	public:

		SwapChainDX11(  );
		~SwapChainDX11();

		/*
		* Init the SwapChain
		*/
		void Init( RenderWindowDX11* a_owner );

		/*
		* Perform the Flip operation
		*/
		void Flip();
	
	// Methods
	private:

		void SetDescriptor( );


	// Fields
	private:
		
		// Pointer to the owner window
		RenderWindowDX11*	m_owner;

		SWAP_CHAIN_DESC	m_swapchainDesc;

		DXGISwapChain*	m_swapchain;

	};
}

#endif