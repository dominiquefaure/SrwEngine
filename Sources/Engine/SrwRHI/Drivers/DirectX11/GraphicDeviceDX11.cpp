#include "GraphicDeviceDX11.h"

#include "PlatformDefineDX11.h"
#include "UtilsDx11.h"

#include "RenderWindowDX11.h"

namespace SrwEngineRHI
{


	//-------------------------------------------------------------------------------
	GraphicDeviceDX11::GraphicDeviceDX11()
	{
		m_windowHandle										=	NULL;
		m_d3dDevice											=	NULL;
		m_immediateContext									=	NULL;
	}
	//-------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------
	GraphicDeviceDX11::~GraphicDeviceDX11()
	{
	}
	//-------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------
	void GraphicDeviceDX11::Initialize( HWND a_windowHandle )
	{
		m_windowHandle										=	a_windowHandle;

		
		CreateDXGIFactory( DX11_IID_PPV_ARGS( &m_deviceFactory ) );

		if(! CreateD3dDevice() )
		{
			//todo stop the Program
		}

	}
	//-------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------
	void GraphicDeviceDX11::Release()
	{

	}
	//-------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------
	SrwBool GraphicDeviceDX11::CreateD3dDevice()
	{
		// Support only Hardware mode
		D3D_DRIVER_TYPE t_driverType						=	D3D_DRIVER_TYPE_HARDWARE;

		SrwUint32 t_creationFlags							=	0;

		D3D_FEATURE_LEVEL t_featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0,
		};
		SrwUint32 t_featureLevelsCount						=	sizeof(t_featureLevels) / sizeof(t_featureLevels[0]);

		// Try to Create the Device
		DX11_CALL(	D3D11CreateDevice(	NULL,
										t_driverType,
										NULL,
										t_creationFlags,
										t_featureLevels,
										t_featureLevelsCount,
										D3D11_SDK_VERSION,
										&m_d3dDevice,
										&m_selectedFeatureLevel,
										&m_immediateContext));

		return m_d3dDevice != NULL;
	}
	//-------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------
	ARenderWindow* GraphicDeviceDX11::CreatePrimaryRenderWindow( const RenderWindowParams& a_params )
	{
		m_primaryRenderWindow								=	new RenderWindowDX11();

		m_primaryRenderWindow->Init( a_params );

		return m_primaryRenderWindow;
	}
	//-------------------------------------------------------------------------------
}