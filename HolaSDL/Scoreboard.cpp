#include "Scoreboard.h"

typedef unsigned uint;

Scoreboard::Scoreboard() :esqIzq(), ancho(), alto(), points(),arrows() {
	Puntuacion(0);
	Arrows(MAX_ARROW_TEXTURES);
}
Scoreboard::Scoreboard(Point2D esqIzq, uint ancho, uint alto, Texture* points,Texture* arrows, int totalArrows, int score) : esqIzq(esqIzq), ancho(ancho), alto(alto), points(points),arrows(arrows), totalArrows(totalArrows), score(score)
{
	mScore.push_back(points);
}


Scoreboard::~Scoreboard() {
	ClearBoard();
}
void Scoreboard::ClearBoard() {
	for (int i = 0; i < mScore.size(); i++)
	{
		delete mScore[i];
		mScore[i] = NULL;

		
	}
	for (int i = 0; i < MAX_ARROW_TEXTURES; i++)
	{
		delete TextArrows[i];
		TextArrows.erase(TextArrows.begin() + i);
	}
	mScore.clear();
	
}
void Scoreboard::Arrows(int arrows)
{
	
	delete TextArrows[arrows];
	TextArrows.erase(TextArrows.begin() + arrows);

	
}
void Scoreboard::Puntuacion(int score)
{
	this->score = this->score + score;
	
	
}
void Scoreboard::render()
{
	SDL_Delay(100);
	
	SDL_Rect srcDest;
	srcDest.x = esqIzq.getX();
	srcDest.y = esqIzq.getY();
	srcDest.w = ancho;
	srcDest.h = alto;
	int unidad = score % 10;
	int decena = score / 10;
	vector<int>digitos;
	for (int i = 0; i < mScore.size(); i++)
	{

		mScore[i]->renderFrame(srcDest, 0, digitos[i], 0, SDL_FLIP_NONE);

	}
	srcDest.x = esqIzq.getX() - 40;
	mScore[1]->renderFrame(srcDest, 0, decena, 0, SDL_FLIP_NONE);

		
	//	arrows->render(srcDest, SDL_FLIP_NONE);
		
}

void Scoreboard::update() {

	if (score == 9)mScore.push_back(points);
}
vector<int>Scoreboard::DameVector()
{
	int aux = score;
	
	
	int digits= 3;
	
	
	do
	{
		aux = aux / 10;
		if(aux<9)
		{
			digitos.push_back(aux);

		}
		digitos.push_back(aux % 10);

	} while (aux<10);

	

}
