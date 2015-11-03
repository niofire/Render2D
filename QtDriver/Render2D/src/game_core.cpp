#include "game_core.h"

#include <string>
#include <iostream>
#include <thread>
#include "base_render2d_context.h"



namespace Render2D
{
	GameCore::GameCore()
	{
		_is_game_core_running = false;
	}


	GameCore::~GameCore()
	{

	}


	void GameCore::reset()
	{

	}

	void GameCore::exit()
	{
		this->_is_game_core_running = false;
	}

	void GameCore::main_loop()
	{
		while (s_core->is_running()){
			s_core->update();
			s_core->render();
			s_core->_render_context->swap_buffers();
		}
	}

	GameCore* GameCore::s_core;

	GameCore* GameCore::execute(BaseRender2DContext* context)
	{
		if (s_core != NULL)
			return NULL;
		s_core = new GameCore;

		//Assign the rendering context
		s_core->_render_context = context;
		if (context == NULL)
			return NULL;


		// Start multithreaded main loop here
		s_core->init();


		//Bind the context to current thread.
		context->bind_context();
		//---------------------------------------------------
		//			Native App entry point
		//---------------------------------------------------
		/*while (s_core->is_running())
			s_core->main_loop();
			*/
		
		s_core->thread = std::thread(s_core->main_loop);
		
		return s_core;
	}

}
