
#ifndef __SRW_ENGINE_RHI_IGRAPHIC_DEVICE_H___
#define __SRW_ENGINE_RHI_IGRAPHIC_DEVICE_H___

#include <windows.h>

#include "./Common/RenderWindowParams.h"
#include "./Common/ARenderVindow.h"


namespace SrwEngineRHI
{

	class IGraphicDevice
	{
	public:

		/*
		* Initialize the Graphic Device
		*/
		virtual void Initialize( HWND a_windowHande ) = 0;

		/*
		* Release the Graphic Device
		*/
		virtual void Release() = 0;

		/*
		* Create the Primary Render Window the Game will be render on
		*/
		virtual ARenderWindow* CreatePrimaryRenderWindow( const RenderWindowParams& a_params ) = 0;
	};
}



#endif