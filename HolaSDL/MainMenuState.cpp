#include "MainMenuState.h";
#include "GameState.h";

const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update()
{

	/*for (GameObject* ob : m_gameObjects)
	{
		ob->update();
	}*/


}
void MainMenuState::render()
{

	/*for (GameObject* ob : m_gameObjects)
	{
		ob->render();
	}*/
}
void MainMenuState::handleEvent() {

}

//bool MainMenuState::onEnter()
//{
//	/*if (!TheTextureManager::Instance()->load("assets/button.png",
//		"playbutton", TheGame::Instance()->getRenderer()))
//	{
//		return false;
//	}
//	if (!TheTextureManager::Instance()->load("assets/exit.png",
//		"exitbutton", TheGame::Instance()->getRenderer()))
//	{
//		return false;
//	}
//	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400,
//100, "playbutton"), s_menuToPlay);
//GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400,
//100, "exitbutton"), s_exitFromMenu);
//	m_gameObjects.push_back(button1);
//	m_gameObjects.push_back(button2);
//	std::cout << "entering MainMenuState\n";
//	return true;*/
//}
//bool MainMenuState::onExit()
//{
//	/*for (int i = 0; i < m_gameObjects.size(); i++)
//	{
//		m_gameObjects[i]->clean();
//	}
//	m_gameObjects.clear();
//	TheTextureManager::Instance()
//		->clearFromTextureMap("playbutton");
//	TheTextureManager::Instance();
//
//	->clearFromTextureMap("exitbutton");
// std::cout << "exiting MainMenuState\n";
// return true;
//}
//	*/
//}

void MainMenuState::s_menuToPlay()
{
	std::cout << "Play button clicked\n";
/*	TheGame::Instance()->getStateMachine()->changeState(new
		PlayState());*/
}
void MainMenuState::s_exitFromMenu()
{
	std::cout << "Exit button clicked\n";
//	TheGame::Instance()->quit();
	
}