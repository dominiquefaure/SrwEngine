#include "SwapChainDX11.h"
#include "RenderWindowDX11.h"

namespace SrwEngineRHI
{ 
	//-----------------------------------------------------------------------------------------------
	SwapChainDX11::SwapChainDX11( )
	{
		m_swapchain											=	NULL;
		m_owner												=	NULL;
	}
	//-----------------------------------------------------------------------------------------------
	
	//-----------------------------------------------------------------------------------------------
	SwapChainDX11::~SwapChainDX11()
	{
	}
	//-----------------------------------------------------------------------------------------------
	
	//-----------------------------------------------------------------------------------------------
	void SwapChainDX11::Init( RenderWindowDX11* a_owner )
	{
		// Save ref to the owner RenderWindow
		m_owner												=	a_owner;

		// Setup the Swapchain descriptor
		SetDescriptor();
	}
	//-----------------------------------------------------------------------------------------------


	//-----------------------------------------------------------------------------------------------
	void SwapChainDX11::SetDescriptor( )
	{
		ZeroMemory( &m_swapchainDesc, sizeof( m_swapchainDesc ) );
	
		m_swapchainDesc.BufferCount							=	1;
		m_swapchainDesc.SwapEffect							=	DXGI_SWAP_EFFECT_DISCARD;

		// Size
		if( m_owner->GetParams().IsWindowed() )
		{
			m_swapchainDesc.Windowed							=	true;
			m_swapchainDesc.BufferDesc.Width					=	m_owner->GetParams().GetWidth();
			m_swapchainDesc.BufferDesc.Height					=	m_owner->GetParams().GetHeight();
		
		}
		else
		{
			// Todo
		}


		m_swapchainDesc.BufferDesc.Scaling					=	DXGI_MODE_SCALING_STRETCHED;
		m_swapchainDesc.BufferDesc.ScanlineOrdering			=	DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		m_swapchainDesc.BufferDesc.Format					=	DXGI_FORMAT_R8G8B8A8_UNORM;
		m_swapchainDesc.Flags								=	DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

		m_swapchainDesc.BufferDesc.RefreshRate.Numerator	=	m_owner->GetParams().GetRefreshRate();
		m_swapchainDesc.BufferDesc.RefreshRate.Denominator	=	1;


		m_swapchainDesc.OutputWindow						=	m_owner->GetParams().GetOutputWindow();
		m_swapchainDesc.BufferUsage							=	DXGI_USAGE_BACK_BUFFER | DXGI_USAGE_RENDER_TARGET_OUTPUT;

		m_swapchainDesc.SampleDesc.Count					=	1;
		m_swapchainDesc.SampleDesc.Quality					=	0;

	}
	//-----------------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------------
	void SwapChainDX11::Flip()
	{
	
	}
	//-----------------------------------------------------------------------------------------------


}