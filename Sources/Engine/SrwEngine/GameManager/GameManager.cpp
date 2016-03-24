#include "GameManager.h"

#include "../Application/ApplicationWin32.h"


namespace SrwEngine
{
	//---------------------------------------------------------------------------------------------
	GameManager::GameManager()
	{
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	GameManager::~GameManager()
	{
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	void GameManager::SetGame( AGame* a_game )
	{
		m_game												=	a_game;
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	void GameManager::SetApplication( ApplicationWin32* a_app )
	{
		m_application										=	a_app;
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	void GameManager::InitGame()
	{
		m_graphicDevice										=	new GraphicDeviceDX11();
	}
	//---------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------
	void GameManager::Frame()
	{
	}
	//---------------------------------------------------------------------------------------------

}
