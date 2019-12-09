#include "EndState.h"
#include <iostream>

const std::string EndState::s_endID = "END";

void EndState::update()
{
	// nothing for now
}
void EndState::render()
{
	// nothing for now
}
void EndState::handleEvent() {

}
bool EndState::onEnter()
{

	if (!TheTextureManager::Instance()->load("assets/gameover.png",
		"gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/restart.png",
		"restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* gameOverText = new AnimatedGraphic(new
		LoaderParams(200, 100, 190, 30, "gameovertext", 2), 2);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 200,
		200, 80, "mainbutton"), s_gameOverToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300,
		200, 80, "restartbutton"), s_restartPlay);
	m_gameObjects.push_back(gameOverText);
	
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}
bool EndState::onExit()
{
	std::cout << "exiting EndState\n";
	return true;
}

void EndState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new
		MenuState());
}
void EndState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new
		PlayState());
}