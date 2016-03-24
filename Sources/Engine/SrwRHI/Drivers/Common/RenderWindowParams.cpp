#include "RenderWindowParams.h"


namespace SrwEngineRHI
{
	//------------------------------------------------------------------------
	RenderWindowParams::RenderWindowParams()
	{
		m_windowed											=	true;

		m_width												=	0;
		m_height											=	0;
		m_refreshRate										=	60;

		m_hwnd												=	NULL;
	}
	//------------------------------------------------------------------------
	
	//------------------------------------------------------------------------
	RenderWindowParams::~RenderWindowParams()
	{
	}
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	void RenderWindowParams::CloneTo( RenderWindowParams& a_params )const
	{
		a_params.m_windowed									=	m_windowed;

		a_params.m_width									=	m_width;
		a_params.m_height									=	m_height;
		a_params.m_refreshRate								=	m_refreshRate;
	
		a_params.m_hwnd										=	m_hwnd;
	}
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	void RenderWindowParams::SetWindow( HWND a_window , SrwBool a_windowed )
	{
		m_hwnd												=	a_window;
		m_windowed											=	a_windowed;

		// Get the Windows Rect
		RECT t_windowRect;
		GetClientRect( a_window , &t_windowRect );

		m_width												=	t_windowRect.right - t_windowRect.left;
		m_height											=	t_windowRect.bottom - t_windowRect.top;
	}
	//------------------------------------------------------------------------
}