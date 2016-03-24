
#include "RenderWindowDX11.h"

namespace SrwEngineRHI
{
	//--------------------------------------------------------------------------
	RenderWindowDX11::RenderWindowDX11()
	{
		m_device											=	NULL;
		m_swapChain											=	NULL;
	}
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	RenderWindowDX11::~RenderWindowDX11()
	{
		m_device											=	NULL;

		SAFE_DELETE( m_swapChain );
	}
	//--------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	void RenderWindowDX11::Init( const RenderWindowParams& a_params )
	{
		//copy the Parameters
		a_params.CloneTo( m_params );

		// Create the Swapchain an initialize it
		m_swapChain											=	new SwapChainDX11();
		m_swapChain->Init( this );
	}
	//--------------------------------------------------------------------------
}

