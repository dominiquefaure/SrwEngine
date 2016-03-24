#ifndef __APPLICATION_WIN32_H__
#define __APPLICATION_WIN32_H__

#include <Windows.h>

#include "SrwCore.h"
#include "../GameManager/AGame.h"


namespace SrwEngine
{
	class ApplicationWin32
	{
	public:

		ApplicationWin32();
		~ApplicationWin32();



		SrwBool Run( HINSTANCE a_instance, AGame* a_game, LPSTR a_menu );

	private:

		/*
		* Initialize the Window
		*/
		SrwBool Init( HINSTANCE a_instance, LPSTR a_menu );

		/*
		* Main game loop
		*/
		void RunGame();

		/*
		* Close the Application Properly
		*/
		void Close();

	//Methods
	private:

		/*
		* Register the WNDCLASSEX Class
		*/
		SrwBool	RegisterWndClass( );

		/*
		* Create the Window that will store the Game
		*/
		SrwBool	CreateWindowDlg( LPSTR a_menu );

		/*
		* Init the Game Manager
		*/
		void InitGameManager( AGame* a_game );

	//// Fields
	private:
		HINSTANCE		m_hInst;
		HWND			m_hWnd;

		// Does the Application received a Quit Request?
		SrwBool			m_quitRequested;

		SrwBool			m_isInitialized;

		TCHAR			m_strClass[MAX_PATH];
		TCHAR			m_strCaption[MAX_PATH];
		WNDCLASSEX		m_stWcex;

		DWORD			m_dwStyle;
		DWORD			m_dwXPos;
		DWORD			m_dwYPos;
		DWORD			m_dwWidth;
		DWORD			m_dwHeight;
		HANDLE			m_hConsole;



		AGame*			m_game;
	};


}
#endif