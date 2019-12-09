#include "PlayState.h"

PlayState::PlayState(list<GameObject*> _escenario, list<EventHandler*> _eventos, Game* _game) :GameState(_escenario, _eventos, _game) {};

const std::string PlayState::s_playID = "PLAY";

	void PlayState::update()
	{
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		{
			TheGame::Instance()->getStateMachine()->pushState(new
				PauseState());
		}
		for (GameObject* ob : escenario)
		{
			ob->update();
		}
	/*	if (checkCollision(dynamic_cast<SDLGameObject*>
			(m_gameObjects[0]), dynamic_cast<SDLGameObject*>
			(m_gameObjects[1])))//si no hay flechas o mariposas xd */
		//{
			TheGame::Instance()->getStateMachine()->pushState(new
				EndState());
		//}
	}

}
void PlayState::render()
{

	for (GameObject* ob : escenario)
	{
		ob->render();
	}
}
void PlayState::handleEvent() {

}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/helicopter.png",
		"helicopter", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* player = new Bow(new LoaderParams(100, 100, 128,
		55, "helicopter");
	escenario.push_back(player);
	std::cout << "entering PlayState\n";
	return true;
}


bool PlayState::onExit()
{
	for (GameObject* ob : escenario)
	{
		ob->clean();
	}

	escenario.clear();
		TheTextureManager::Instance()
		->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}