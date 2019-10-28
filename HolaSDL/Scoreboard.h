#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include "Vector2D.h"
#include "Texture.h"
#include <vector>
using namespace std;

class Game;
class Scoreboard
{
private:
	vector<Texture*>mScore;
	Point2D esqIzq = Point2D(0, 0);
	Texture* texture;
	uint ancho;
	uint alto;
	static  const int MAX_ARROW_TEXTURES = 10;
	Texture* arrowTextures[MAX_ARROW_TEXTURES];
	int totalArrows;


public:
	Scoreboard();

	Scoreboard(Point2D esqIzq,uint ancho , uint alto ,Texture* textura);
	~Scoreboard();
	void Score(int score);
	void Arrows(int arrows);
		void render();
	void update();
private:
	void ClearBoard();
};
#endif

