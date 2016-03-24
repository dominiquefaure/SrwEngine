
#ifndef __SRW_ENGINE_RHI_RENDER_VINDOW_PARAMS_H___
#define __SRW_ENGINE_RHI_RENDER_VINDOW_PARAMS_H___

#include <windows.h>
#include "SrwCore.h"


namespace SrwEngineRHI
{
	/*
	* Parameters that describe the caracteristics of a RenderWindow to be created
	*/
	class RenderWindowParams
	{
	public:

		RenderWindowParams();
		~RenderWindowParams();

		/*
		* Use Window version or full screen?
		*/
		inline SrwBool IsWindowed()const;

		/*
		* Get the Window Width
		*/
		inline SrwUint32 GetWidth()const;

		/*
		* Get the Window Height
		*/
		inline SrwUint32 GetHeight()const;

		/*
		* Get teh desirate number of Frame per seconds : 60 by default
		*/
		inline SrwUint32 GetRefreshRate()const;

		/*
		* Get the Handle to the Window
		*/
		inline HWND GetOutputWindow()const;


		void CloneTo( RenderWindowParams& a_params )const;

		/*
		* Set the Target window.
		* Width and Height will be set to the window size
		* @param a_window	Handle to the output window
		* @param a_windowed	display windowed or fullscreen
		*/
		void SetWindow( HWND a_window , SrwBool a_windowed = true );

	private:

		SrwBool		m_windowed;

		SrwUint32	m_width;
		SrwUint32	m_height;

		// number of FPS : 60 by default
		SrwUint32	m_refreshRate;

		// Handle to the window to blit in
		HWND		m_hwnd;

	};

	//-------------------------------------------------------------------------------
	inline SrwBool RenderWindowParams::IsWindowed()const
	{
		return m_windowed;
	}
	//-------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------
	inline SrwUint32 RenderWindowParams::GetWidth()const
	{
		return m_width;
	}
	//-------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------
	inline SrwUint32 RenderWindowParams::GetHeight()const
	{
		return m_height;
	}
	//-------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------
	inline SrwUint32 RenderWindowParams::GetRefreshRate()const
	{
		return m_refreshRate;
	}
	//-------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------
	inline HWND RenderWindowParams::GetOutputWindow()const
	{
		return m_hwnd;
	}
	//-------------------------------------------------------------------------------

}



#endif