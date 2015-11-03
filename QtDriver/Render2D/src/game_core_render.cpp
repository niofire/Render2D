#include "game_core.h"
#include "global.h"
namespace Render2D
{

	void GameCore::render()
	{
		glBegin(GL_TRIANGLES);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glVertex3f(1, 0, 0);
		glEnd();
		
		//this->_game_window.swap_buffers();
	}
}