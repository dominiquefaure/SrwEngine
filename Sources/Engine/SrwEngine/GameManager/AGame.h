#ifndef __SRW_ENGINE_A_GAME_H__
#define __SRW_ENGINE_A_GAME_H__


namespace SrwEngine
{

	class AGame
	{
	public:

		AGame();
		virtual ~AGame();
	
		/*
		* Allow Custom Initialization for the Game
		*/
		virtual void OnInit()=0;

	};
};

#endif