#ifndef __SRW_ENGINE_RHI_RENDER_WINDOW_DX11_H___
#define __SRW_ENGINE_RHI_RENDER_WINDOW_DX11_H___

#include <windows.h>

#include "PlatformDefineDX11.h"
#include "SrwCore.h"

#include "../Common/ARenderVindow.h"
#include "SwapChainDX11.h"


namespace SrwEngineRHI
{
	class GraphicDeviceDX11;

	class RenderWindowDX11 : public ARenderWindow
	{
	public:

		RenderWindowDX11(  );
		virtual ~RenderWindowDX11();

		/*
		* Initialize the Render Window
		*/
		void Init( const RenderWindowParams& a_params );

	// Methods
	private:

		inline GraphicDeviceDX11* GetDevice()const
		{
			return m_device;
		}

	// Fields
	private:
	
		GraphicDeviceDX11* m_device;

		SwapChainDX11*	m_swapChain;
	};
}

#endif