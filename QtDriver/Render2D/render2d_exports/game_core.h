#pragma once

#include <thread>
//------------------------------------------------------
//			Game Engine Class
//------------------------------------------------------
// Users need to override the Game Engine class in order
// to create their own.
//
namespace Render2D
{
	class BaseRender2DContext;

	class GameCore
	{
	public:
		virtual ~GameCore();

		//---------------------------------------------------
		//				Game Loop
		//---------------------------------------------------
		static GameCore* execute(BaseRender2DContext* context);

		//--------------------------------------------------
		//				Virtual core function - To override in Users Main Engine
		//--------------------------------------------------
		//  These functions can be overriden by your own GameEngine class

	private:
		bool init();
		void reset();
		void exit();
		void render();
		void update();
		void on_event();

		//---------------------------------------------------
		//				core status function
		//---------------------------------------------------
		inline	bool	is_running() const { return _is_game_core_running; }

		//---------------------------------------------------
		//				Render Environment
		//---------------------------------------------------
		bool			init_render_content(int w, int h);
	protected:

		//holds whether the Game core is currently running
		bool		_is_game_core_running;


	private:
		std::thread thread;
		GameCore();
		BaseRender2DContext* _render_context;
		static void main_loop();
		static GameCore* s_core;
	};
}


