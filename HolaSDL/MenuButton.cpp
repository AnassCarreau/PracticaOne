#include "MenuButton.h"
/*MenuButton::MenuButton(const LoaderParams* pParams) :SDLGameObject(pParams)
{
//	m_currentFrame = MOUSE_OUT; // start at frame 0
}*/
MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()
) : SDLGameObject(pParams), m_callback(callback)
void MenuButton::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}
void MenuButton::clean()
{
	SDLGameObject::clean();
}
void MenuButton::update()
{
	SDL_Event event;
	Vector2D* pMousePos = new Vector2D(event.button.x, event.button.y);
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		if (event.type == SDL_MOUSEBUTTONDOWN )
		{

		if (m_bReleased)
		{
			//m_currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else
		{
			
				m_bReleased = true;
				m_currentFrame = MOUSE_OVER;
			
		}
			
		}
	}
	else
	{
		//m_currentFrame = MOUSE_OUT;
	}
//Moruma Arriva con v
	using CallBackOnClick = void(Game * game);
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		//m_currentFrame = MOUSE_OVER;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			//m_currentFrame = CLICKED;
		}
	}
	else
	{
		//m_currentFrame = MOUSE_OUT;
	}
}