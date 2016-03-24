#include "ApplicationWin32.h"

#include "../GameManager/GameManager.h"

// Callback that will be Called to Handle Windows Messages
LRESULT CALLBACK AppWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

namespace SrwEngine
{

	//--------------------------------------------------------------------------------------------------------------
	ApplicationWin32::ApplicationWin32()
	{
		m_quitRequested											=	false;
		m_isInitialized											=	false;

		m_game													=	NULL;
	}
	//--------------------------------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------------------------------
	ApplicationWin32::~ApplicationWin32()
	{

	}
	//--------------------------------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------------------------------
	SrwBool ApplicationWin32::Run(HINSTANCE a_instance, AGame* a_game , LPSTR a_menu)
	{

		Init( a_instance , a_menu );


		InitGameManager( a_game );

		// Run the Game until the user want to Quit
		RunGame();

		// Close the Application Properly
		Close( );

		return TRUE;
	}
	//--------------------------------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------------------------------
	SrwBool ApplicationWin32::Init( HINSTANCE a_instance, LPSTR a_menu )
	{
		m_hInst													=	a_instance;
		m_quitRequested											=	false;
		m_isInitialized											=	false;

		strcpy_s( m_strClass, "Test1" );
		strcpy_s( m_strCaption, "Application Caption" );

		// register the Class for the window
		if( !RegisterWndClass() )
		{
			return false;
		}

		// Create the window used to Display the Game
		if( ! CreateWindowDlg( a_menu ) )
		{
			return false;
		}

		m_isInitialized											=	true;

		// Show the window and Perform 1st Update
		ShowWindow( m_hWnd, SW_NORMAL );
		UpdateWindow( m_hWnd );

		return true;
	}
	//--------------------------------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------------------------------
	void ApplicationWin32::RunGame()
	{
		MSG t_msg;

		ZeroMemory( &t_msg, sizeof( MSG ) );

		// Loop Until the User want To Quit
		while(! m_quitRequested )
		{
			// if a Message have been received
			if ( PeekMessage( &t_msg, NULL, 0, 0, PM_REMOVE ) )
			{
				// Process the Message
				TranslateMessage( &t_msg );
				DispatchMessage( &t_msg );

				// if the User close the window
				if( t_msg.message == WM_QUIT )
				{
					break;
				}
			}
			else
			{
				if( m_isInitialized )
				{
					// Perform a Frame
					GameManager::GetInstance()->Frame();
				}
			}
		}

	}
	//--------------------------------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------------------------------
	void ApplicationWin32::Close()
	{

		UnregisterClass( m_strClass, m_hInst );
	}
	//--------------------------------------------------------------------------------------------------------------


	//--------------------------------------------------------------------------------------------------------------
	SrwBool	ApplicationWin32::RegisterWndClass( )
	{
		m_dwStyle												=	WS_OVERLAPPEDWINDOW;
		m_dwXPos												=	0;
		m_dwYPos												=	0;
		m_dwWidth												=	1280;
		m_dwHeight												=	720;

		// Define the windows Properties
		m_stWcex.cbSize											=	sizeof(WNDCLASSEX);
		m_stWcex.style											=	CS_OWNDC;
		m_stWcex.lpfnWndProc									=	AppWindowProc;
		m_stWcex.cbClsExtra										=	0;
		m_stWcex.cbWndExtra										=	0;
		m_stWcex.hInstance										=	m_hInst;
		m_stWcex.hIcon											=	LoadIcon( NULL, IDI_APPLICATION );
		m_stWcex.hCursor										=	LoadCursor( NULL, IDC_ARROW );
		m_stWcex.hbrBackground									=	( HBRUSH ) ( COLOR_WINDOW + 1 );
		m_stWcex.lpszMenuName									=	NULL;
		m_stWcex.lpszClassName									=	m_strClass;
		m_stWcex.hIconSm										=	LoadIcon( NULL, IDI_APPLICATION );

 		if ( !RegisterClassEx( &m_stWcex ) )
		{
			return false;
		}

		return true;
	}
	//--------------------------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------
	/*
	* Create the Window that will store the Game
	*/
	SrwBool ApplicationWin32::CreateWindowDlg(  LPSTR a_menu )
	{
		HMENU t_hMenu											=	NULL;

		// Load the Menu if Needed
		if( a_menu != NULL )
		{
			t_hMenu												=	LoadMenu( m_hInst, a_menu );

		}

		// Create the Window
		m_hWnd													=	CreateWindowEx(	WS_EX_CLIENTEDGE,
																					m_strClass,
																					m_strCaption,
																					m_dwStyle, 
																					m_dwXPos,
																					m_dwYPos,
																					m_dwWidth,
																					m_dwHeight,
																					NULL,
																					t_hMenu,
																					m_hInst,
																					NULL );
		// If the Creation Failed
		if ( !m_hWnd )
		{
			return false;
		}


		RECT rect;
		SetRect( &rect, 0, 0, m_dwWidth, m_dwHeight );
		AdjustWindowRectEx( &rect, m_dwStyle, GetMenu( m_hWnd ) != NULL, 0 );

		int child_windowWidth									=	rect.right - rect.left;
		int child_windowHeight									=	rect.bottom - rect.top;
		int parent_windowWidth									=	GetSystemMetrics( SM_CXSCREEN );
		int parent_windowHeight									=	GetSystemMetrics( SM_CYSCREEN );
		int posx												=	( parent_windowWidth - child_windowWidth ) / 2;
		int posy												=	( parent_windowHeight - child_windowHeight ) / 2;


		MoveWindow( m_hWnd, posx, posy, rect.right - rect.left, rect.bottom - rect.top, TRUE );


		return TRUE;
	}
	//---------------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------
	void ApplicationWin32::InitGameManager( AGame* a_game )
	{
		// Create the Game Manager
		GameManager::CreateInstance();

		GameManager::GetInstance()->SetApplication( this );
		GameManager::GetInstance()->SetGame( a_game );

		GameManager::GetInstance()->OnInit( );

	}
	//---------------------------------------------------------------------------------------------------
}

//--------------------------------------------------------------------------------------------------------------
LRESULT CALLBACK AppWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch( message )
	{
	    case WM_CLOSE:
		    DestroyWindow(hWnd);
		    PostQuitMessage(0);
        break;
	
	}

    return DefWindowProc(hWnd, message, wParam, lParam);

}
//--------------------------------------------------------------------------------------------------------------
