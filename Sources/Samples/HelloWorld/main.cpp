#include<Windows.h>

#include"SrwEngine.h"

#include "HelloGame.h"

using namespace SrwEngine;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
					LPWSTR cmdLine, int cmdShow)
{

	HelloGame t_game;

	ApplicationWin32 t_appli;

	t_appli.Run( hInstance, &t_game , NULL );

	return 0;
}
