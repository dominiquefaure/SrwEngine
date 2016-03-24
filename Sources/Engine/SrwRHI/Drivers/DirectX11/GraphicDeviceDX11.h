
#ifndef __SRW_ENGINE_RHI_GRAPHIC_DEVICE_DX11_H___
#define __SRW_ENGINE_RHI_GRAPHIC_DEVICE_DX11_H___

#include <windows.h>

#include "../IGraphicDevice.h"


#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

#include "SrwCore.h"


namespace SrwEngineRHI
{
	class RenderWindowDX11;


	class GraphicDeviceDX11 : public IGraphicDevice
	{
	public:

		GraphicDeviceDX11();
		~GraphicDeviceDX11();

		/*
		* Initialize the Graphic Device
		*/
		virtual void Initialize( HWND a_windowHandle );

		/*
		* Release the Graphic Device
		*/
		virtual void Release();

		/*
		* Create the Primary Render Window the Game will be render on
		*/
		virtual ARenderWindow* CreatePrimaryRenderWindow( const RenderWindowParams& a_params );


	// MEthods
	private:

		/*
		* Try to Create teh D3D Device
		*/
		SrwBool CreateD3dDevice();

	// Fields
	private:
		HWND			m_windowHandle;


		ID3D11Device*			m_d3dDevice;
		ID3D11DeviceContext*	m_immediateContext;

		D3D_FEATURE_LEVEL		m_selectedFeatureLevel;

		IDXGIFactory*			m_deviceFactory;


		RenderWindowDX11*		m_primaryRenderWindow;


	};
}



#endif