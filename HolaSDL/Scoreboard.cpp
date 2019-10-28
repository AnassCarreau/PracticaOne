#include "Scoreboard.h"

Scoreboard::Scoreboard() :esqIzq(), ancho(), alto(), texture() {
	Score(0);
}
Scoreboard::Scoreboard(Point2D esqIzq, uint ancho, uint alto, Texture* textura) : esqIzq(esqIzq), ancho(ancho), alto(alto), texture(textura) {}


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
		delete arrowTextures[i];
		arrowTextures[i] = NULL;
	}
	mScore.clear();
	
}
void Scoreboard::Arrows(int arrows)
{
	
	delete arrowTextures[arrows];
	arrowTextures[arrows] = NULL;
	
}
void Scoreboard::Score(int score)
{
	ClearBoard();
	if (score == 0) {
		for (int i = 0; i < 2; i++)
		{
			//	mScore.push_back(new Texture("render","..\\images\\digits.png", 1, 1,));
			//parent
			//pos
		}

	}
	else
	{
		string str = to_string(score);
		int lastIndex = str.length() - 1;
		for (int i = 0; i <= lastIndex; i++)
		{
			//	mScore.push_back(new Texture("render","..\\images\\digits.png", 1, 1,));
			//parent
			//pos
			//str.substr(i, 1);
		}

	}
}
	void Scoreboard::render()
	{
		SDL_Rect srcDest;
		srcDest.x = esqIzq.getX();
		srcDest.y = esqIzq.getY();
		srcDest.w = ancho;
		srcDest.h = alto;
		int puntuacion=0;
		texture->renderFrame(srcDest,0,puntuacion,0,SDL_FLIP_NONE);
		for (int i = 0; i < mScore.size() ; i++)
		{
			//mScore[i]->render();
		}
	}
