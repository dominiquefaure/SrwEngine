#ifndef __SRW_ENGINE_GAME_MANAGER_H__
#define __SRW_ENGINE_GAME_MANAGER_H__

#include "SrwCore.h"
#include "AGame.h"

using namespace SrwCore;


namespace SrwEngine
{
	class ApplicationWin32;

	class GameManager : public Singleton<GameManager>
	{
		friend class Singleton<GameManager>;

	public:
	
		/*
		* Set the Game Instance
		*/
		void SetGame( AGame* a_game );

		/*
		* Set the Launcher Application
		*/
		void SetApplication( ApplicationWin32* a_app );

		/*
		* Initialize the Game
		*/
		void InitGame();

		/*
		* Process a Game Frame
		*/
		void Frame();

	private:

		GameManager();
		virtual ~GameManager();

	private:

		// The Game to run
		AGame*				m_game;

		// The Application that launch the Game
		ApplicationWin32*	m_application;
	};

}

#endif