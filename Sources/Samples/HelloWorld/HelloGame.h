#ifndef __HELLO_GAME_H__
#define __HELLO_GAME_H__

#include "SrwEngine.h"

using namespace SrwEngine;


class HelloGame : public AGame
{
public:

	HelloGame();

	/*
	* Allow Custom Initialization for the Game
	*/
	virtual void OnInit();

	

};

#endif