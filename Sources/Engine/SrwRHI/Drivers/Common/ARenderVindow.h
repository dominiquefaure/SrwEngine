
#ifndef __SRW_ENGINE_RHI_A_RENDER_VINDOW_H___
#define __SRW_ENGINE_RHI_A_RENDER_VINDOW_H___

#include <windows.h>
#include "SrwCore.h"

#include "RenderWindowParams.h"

namespace SrwEngineRHI
{


	/*
	* Represent a Window were the render will occurs.
	* Usually only 1 per game
	* Can use more for tools
	*/
	class ARenderWindow
	{
	public:


		inline const RenderWindowParams& GetParams();

	protected:
		ARenderWindow(){}
		virtual ~ARenderWindow(){}

	protected:
		RenderWindowParams	m_params;
	};

	const RenderWindowParams& ARenderWindow::GetParams()
	{
		return m_params;
	}

}



#endif