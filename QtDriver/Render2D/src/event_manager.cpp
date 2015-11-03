#include "event_manager.h"
#include "event_listener.h"
#include "render2D_typedef.h"

namespace Render2D
{
EventManager::EventManager()
{
	m_EventListenersDA.resize(NUMBER_OF_EVENTS,std::vector<EventListener*>());
}

EventManager::~EventManager()
{

}

void EventManager::Register(EventListener* eListener, EventManager::Render2DEvent e)
{
	m_EventListenersDA[e].push_back(eListener);
}

void EventManager::UpdateEventManager()
{
	SDL_Event Event;
	while(SDL_PollEvent(&Event)) {

		Render2DEvent l_eType = SDL_To_Lode(&Event);
		//EventListener list correlating to the currently dispatched event
		std::vector<EventListener*> *EventListenerList = &m_EventListenersDA[l_eType];
		U32 l_ListSize = EventListenerList->size();

		switch(l_eType)
		{
		case WINDOW_RESIZE:
			for(U32 i = 0; i < l_ListSize; ++i)
				(*EventListenerList)[i]->OnResize(Event.window.data1,Event.window.data2);
			break;
			
		case KEYBOARD_DOWN:
			for(U32 i = 0; i < l_ListSize; ++i)
				(*EventListenerList)[i]->OnKeyDown(SDL_GetKeyboardState(NULL));
			break;
		case KEYBOARD_UP:
			for(U32 i = 0; i < l_ListSize; ++i)
				(*EventListenerList)[i]->OnKeyUp(SDL_GetKeyboardState(NULL));
			break;				
		case	MOUSE_MIDDLE_BUTTON_UP:
			for(U32 i = 0; i < l_ListSize; ++i)
				(*EventListenerList)[i]->OnMButtonUp(Event.button.x,Event.button.y);
	
		case	MOUSE_MIDDLE_BUTTON_DOWN:
			for(U32 i = 0; i < l_ListSize; ++i)
			{				
				(*EventListenerList)[i]->OnMButtonDown(Event.button.x,Event.button.y);
			}
		}
	}
}


EventManager::Render2DEvent EventManager::SDL_To_Lode(SDL_Event* Event)
{
	switch(Event->type) {


	case SDL_WINDOWEVENT: 
		
		switch (Event->window.event) {
		case SDL_WINDOWEVENT_RESIZED:
			return WINDOW_RESIZE;
			break;
		case SDL_WINDOWEVENT_MINIMIZED:
			return WINDOW_MINIMIZE;
			break;
		case SDL_WINDOWEVENT_MAXIMIZED:
			return WINDOW_MAXIMIZE;
			break;
		case SDL_WINDOWEVENT_RESTORED:
			return WINDOW_RESTORE;
			break;
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			return WINDOW_KEYBOARD_INPUT_FOCUS;
			break;
		case SDL_WINDOWEVENT_FOCUS_LOST:
			return WINDOW_KEYBOARD_INPUT_UNFOCUS;
			break;
		case SDL_WINDOWEVENT_CLOSE:
			return WINDOW_EXIT;
			break;
		default:
			return  UNHANDLED_EVENT;
			break;
		};
		break;
	case SDL_KEYDOWN: 
		return KEYBOARD_DOWN;
		break;
	case SDL_KEYUP: 
		return KEYBOARD_UP;
		break;		
	case SDL_MOUSEMOTION: 
		return MOUSE_MOVE;
		break;
	case SDL_MOUSEBUTTONDOWN: 
		switch(Event->button.button) {
		case SDL_BUTTON_LEFT: 
			return MOUSE_LEFT_BUTTON_DOWN;
			break;
							  
		case SDL_BUTTON_RIGHT: 
			return MOUSE_RIGHT_BUTTON_DOWN;
			break;
							   
		case SDL_BUTTON_MIDDLE: 
			return MOUSE_MIDDLE_BUTTON_DOWN;
			break;
								
		}
		break;
							  

	case SDL_MOUSEBUTTONUP:  

		switch(Event->button.button) {
		case SDL_BUTTON_LEFT: 
			return MOUSE_LEFT_BUTTON_UP;
			break;			  
		case SDL_BUTTON_RIGHT: 
			return MOUSE_RIGHT_BUTTON_UP;
			break;				   
		case SDL_BUTTON_MIDDLE: 
			return MOUSE_MIDDLE_BUTTON_DOWN;
			break;
		}   

	case SDL_QUIT: 
		return WINDOW_EXIT;
		break;

	default: 
		return UNHANDLED_EVENT;
		break;
			 
	};
	return UNHANDLED_EVENT;
}

}