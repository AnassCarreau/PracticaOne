#include "Scoreboard.h"

using namespace std;
Scoreboard::Scoreboard() :esqIzq(), ancho(), alto(), points(),arrows() {
	Puntuacion(0);
	
}
Scoreboard::Scoreboard(Point2D esqIzq, uint ancho, uint alto, Texture* points,Texture* arrows, int totalArrows, int score) : esqIzq(esqIzq), ancho(ancho), alto(alto), points(points),arrows(arrows), totalArrows(totalArrows), score(score)
{
	for (int i = 0; i < totalArrows; i++)
	{
		TextArrows.push_back(arrows);
	}
}


Scoreboard::~Scoreboard() {
	ClearBoard();
}
void Scoreboard::ClearBoard() {
	/*for (int i = 0; i < mScore.size(); i++)
	{
		delete mScore[i];
		mScore.erase(mScore.begin()+i);
		
		
	}
	/*for (int i = 0; i < MAX_ARROW_TEXTURES; i++)
	{
		delete TextArrows[i];
		TextArrows.erase(TextArrows.begin() + i);
	}
	mScore.clear();*/
	
}
void Scoreboard::Arrows()
{
	/*delete TextArrows[totalArrows];
	TextArrows.erase(TextArrows.begin() + totalArrows);*/
	//no puedo  debugear pero si puedes lo haces eleminando el elemento bn 
	totalArrows--;

	
}
void Scoreboard::Puntuacion(int score)
{
	this->score = this->score + score;
	cout << this->score;


	
}
void Scoreboard::render(){
	vector<Texture*>mScore;
	vector<int>digitos;
	DameVector(digitos,mScore);
	SDL_Rect srcDest;
	srcDest.x = esqIzq.getX();
	srcDest.y = esqIzq.getY();
	srcDest.w = ancho;
	srcDest.h = alto;
	for (int i = 0; i < digitos.size(); i++)
	{
		srcDest.x -=20;

		mScore[i]->renderFrame(srcDest, 0, digitos[i], 0, SDL_FLIP_NONE);

	}
	for (int i = 0; i < totalArrows; i++)
	{
		srcDest.x -= 25;

		TextArrows[i]->render(srcDest, SDL_FLIP_NONE);
	}
		
		
}


void Scoreboard::DameVector(vector<int>&digitos, vector<Texture*>&mScore)
{
	int aux = score;
	
	do
	{
		digitos.push_back(aux % 10);
		mScore.push_back(points);

		aux = aux / 10;

	} while (aux > 9);
	digitos.push_back(aux);
	mScore.push_back(points);

}

