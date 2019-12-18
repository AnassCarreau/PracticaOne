#include "PlayState.h";
#include "GameState.h";
#include "checkML.h"


const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState(Game* _game, bool _cargar) :GameState(_game) {
	cargar = _cargar;
	pauseButton = new MenuButton(Point2D(750, 0), 50, 50, game->GetTexture(10), this, PauseCallback);
	scoreboard = new Scoreboard(Point2D(300, 0), 25, 35, game->GetTexture(5), game->GetTexture(4), NUM_FLECHAS);
	objects.push_back(scoreboard);
	objects.push_back(pauseButton);
	eventHandler.push_back(pauseButton);
	startBaloonTime = SDL_GetTicks();
	ifstream input;
	if (cargar) {
		loadFroamFile(input);
	}
	else
	{
		Bow* arco = new Bow(Point2D(0, 100), 80, 80, Vector2D(0, 10), game->GetTexture(0), game->GetTexture(2), this);
		objects.push_back(arco);
		arco->setItList(--objects.end());
		eventHandler.push_back(arco);
		NewLvl(0);
	}

};

PlayState::~PlayState() {
	GameState::~GameState();
	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		objectsToErase.push_back(*it);
	}
	for (auto it = objectsToErase.begin(); it != objectsToErase.end(); ++it)
	{
		objects.remove(*it);
		eventHandler.remove(dynamic_cast<EventHandler*>(*it));
		arrows.remove(dynamic_cast<Arrow*>(*it));
		delete* it;

	}
	delete fondo;
	fondo = nullptr;
	objectsToErase.clear();
	arrows.clear();
	objects.clear();
	eventHandler.clear();
}
void PlayState::update()
{	
	if (level >= 5) {
		game->YouWin();
	}
	if (NUM_BUTTERFLYS <= 0 || NUM_FLECHAS <= 0) {
		game->GameOver();
	}
	else {
		GameState::update();
		generateBalloons();

		for (auto it = objectsToErase.begin(); it != objectsToErase.end(); ++it)
		{
			objects.remove(*it);
			eventHandler.remove(dynamic_cast<EventHandler*>(*it));
			arrows.remove(dynamic_cast<Arrow*>(*it));
			delete* it;
		}

		objectsToErase.clear();
	}
}

void PlayState::render()
{
	//renderizado del fondo
	SDL_Rect bk;
	bk = { 0,0,WIN_WIDTH,WIN_HEIGHT };

	fondo->render(bk, SDL_FLIP_NONE);
	GameState::render();
}


void PlayState::generateBalloons() {

	const int FRAME_RATEGLOB = 500; // cada dos segundos generamos un globo
	frameBaloonTime = SDL_GetTicks() - startBaloonTime;
	if (frameBaloonTime >= FRAME_RATEGLOB) {
		int h = rand() % 320 + 400;
		int color = rand() % 7;
		double velocidad = rand() % (int)VEL_BUT.max + VEL_BUT.min;
		Balloon* globo = new  Balloon(Point2D{ (double)h,600 }, 80, 80, Vector2D(0, -velocidad), game->GetTexture(1), false, 0, this, color);
		auto it = objects.insert(objects.end(), globo);
		globo->setItList(it);

		startBaloonTime = SDL_GetTicks();
	}

}
//metodo que coge el tiempo de carga de la flecha
void PlayState::CargaFlecha()
{
	timecharge = SDL_GetTicks();
}
//metodo para disparar la flecha
void PlayState::DisparaFlecha(Point2D pos) {
	//le llega a dispara flecha una flecha 
	/*auto it=object.insert(object.end(),arrow)
	arrows->setit(it)
	*/
	if (NUM_FLECHAS != 0)
	{
		timeshoot = SDL_GetTicks();
		timecharge = (timeshoot - timecharge) / 1000;
		if (timecharge > 10)
		{
			timecharge = 10;
		}
		Arrow* flecha = new Arrow(Vector2D(timecharge + 4, 0), game->GetTexture(3), this, Point2D(pos.getX() + 20, pos.getY() + 30), 90 + arrowsSize, 20 + arrowsSize);
		auto it = objects.insert(objects.end(), flecha);
		arrows.push_back(flecha);
		flecha->setItList(it);
		NUM_FLECHAS--;

		/*objects.push_back(flecha);
		flecha->setItList(--objects.end());*/

		scoreboard->Arrows(NUM_FLECHAS);
	}
}
//metodo para añadir puntos
void PlayState::AddPoints(int pointsadd, int hits)
{
	if (hits <= 0) {
		puntuacion += pointsadd;
	}
	else {
		puntuacion += pointsadd + sqrt(hits - 1) * pointsadd;
	}
	if (puntuacion >= 0)
	{
		scoreboard->Puntuacion(puntuacion);

	}
	if (puntuacion / 100 > level)
	{
		level++;
		NewLvl(level);
	}
}



//metodo que mira si alguna flecha ha tocado con un globo
bool PlayState::OnCollisionEnter(SDL_Rect rect, list<GameObject*>::iterator collider) {

	for (auto it = arrows.begin(); it != arrows.end(); ++it)
	{
		if (SDL_HasIntersection(&rect, &(*it)->getCollisionRect()))
		{
			if (dynamic_cast<Balloon*>(*collider) != nullptr)
			{
				AddPoints(POINTS, (*it)->getHits());
				int estadistica = rand() % 1;
				if (estadistica == 0) {
					double y = (double)rect.y + rect.h;
					CreateReward(Point2D(rect.x, y));
				}
			}
			else if (dynamic_cast<Butterfly*>(*collider) != nullptr)
			{
				AddPoints(-POINTS / 2, 0);
				NUM_BUTTERFLYS--;

			}
			return true;
		}
	}
	return false;
}

void PlayState::KillObject(list<GameObject*>::iterator it) {

	objectsToErase.push_back(*it);
}

void PlayState::CreateButterflys() {
	int posiX, posiY;
	double velX, velY;
	for (uint j = 0; j < NUM_BUTTERFLYS; j++) {
		posiX = rand() % 600 + 100;
		posiY = rand() % 400 + 100;
		velX = rand() % (int)VEL_BUT.max - VEL_BUT.min;
		velY = rand() % (int)VEL_BUT.max - VEL_BUT.min;

		Butterfly* mariposa = new Butterfly(Point2D((double)posiX, (double)posiY), Vector2D(velX, velY), 60, 60, game->GetTexture(6), this);
		auto it = objects.insert(objects.end(), mariposa);
		mariposa->setItList(it);
	}
}
void PlayState::CreateReward(Point2D pos)
{
	int color = rand() % 2;
	Reward* premio = nullptr;
	switch (color)
	{
	case 0: premio = new GiveMeArrows(pos, Vector2D(0, 0.1), 100, 70, game->GetTexture(7), game->GetTexture(8), this, color);
		break;
	case 1: premio = new BigArrows(pos, Vector2D(0, 0.1), 100, 70, game->GetTexture(7), game->GetTexture(8), this, color);
		break;

	}
	eventHandler.push_back(premio);
	auto et = objects.insert(objects.end(), premio);
	premio->setItList(et);

}

void PlayState::NewLvl(int _level)
{
	level = _level;
	fondo = new Texture(game->GetRenderer(), niveles[level].filename, 1, 1);
	for (auto it = objects.begin(); it != objects.end(); ++it) {
		if (dynamic_cast<Bow*>(*it) == nullptr && dynamic_cast<Scoreboard*>(*it) == nullptr && dynamic_cast<MenuButton*>(*it) == nullptr)
		{
			objectsToErase.push_back(*it);
			eventHandler.remove(dynamic_cast<Reward*>(*it));
		}

	}
	arrows.clear();
	arrowsSize = 0;
	NUM_FLECHAS = niveles[level].numFlecha;
	NUM_BUTTERFLYS = niveles[level].numMariposas;
	VEL_BAL = niveles[level].velBal;
	VEL_BUT = niveles[level].velBut;
	scoreboard->Arrows(NUM_FLECHAS);
	CreateButterflys();
}

void PlayState::saveToFile(ofstream& output) {
	//abrimos el archivo
	output.open("guardados.txt");
	//si no se abre lanzamos excepcion
	if (!output.is_open()) throw FileNotFoundError("No se encuentra el archivo");
	//si se puede abrir guardamos la partida
	else {
		output << level << endl;
		output << puntuacion << endl;
		output << NUM_FLECHAS << endl;
		int objetos = objects.size();
		output << objetos << endl;
		for (auto it = ++objects.begin(); it != objects.end(); ++it) {
			if (dynamic_cast<MenuButton*>(*it) == nullptr) {
				dynamic_cast<ArrowsGameObject*>(*it)->saveToFile(output);
			}
		}
	}
	output.close();

}

void PlayState::loadFroamFile(ifstream& input) {

	//abrimos el archivo
	input.open("guardados.txt");
	//si no se puede abrir lanzamos una excepcion
	if (!input.is_open()) throw FileNotFoundError("No se encuentra el archivo");
	//si se abre cargamos el archivo
	else {
		input >> level;
		fondo = new Texture(game->GetRenderer(), niveles[level].filename, 1, 1);
		VEL_BAL = niveles[level].velBal;
		VEL_BUT = niveles[level].velBut;
		input >> puntuacion;
		scoreboard->Puntuacion(puntuacion);
		input >> NUM_FLECHAS;
		scoreboard->Arrows(NUM_FLECHAS);
		int obj;
		int color;
		input >> obj;
		string line;
		for (int i = 0; i < obj; i++) {
			input >> line;
			//falta que cada objeto sepa cual es su textura
			if (line == "Mariposa")objects.push_back(new Butterfly(Point2D(NULL, NULL), Vector2D(NULL, NULL), 20, 20, game->GetTexture(6), this));
			else if (line == "Globo")objects.push_back(new Balloon(Point2D(NULL, NULL), 20, 20, Vector2D(NULL, NULL), game->GetTexture(1), false, 0, this, NULL));
			else if (line == "Flecha")
			{
				objects.push_back(new Arrow(Vector2D(NULL, NULL), game->GetTexture(3), this, Point2D(NULL, NULL), 20, 20));
				arrows.push_back(dynamic_cast<Arrow*>(objects.back()));
			}
			else if (line == "Arco") {
				objects.push_back(new Bow(Point2D(0, 0), 20, 20, Vector2D(0, 0), game->GetTexture(0), game->GetTexture(2), this));
				eventHandler.push_back(dynamic_cast<EventHandler*>(objects.back()));
			}
			else if (line == "Premio") {

				input >> color;
				switch (color)
				{
				case 0:
					objects.push_back(new GiveMeArrows(Point2D(0, 0), Vector2D(0, 0), 20, 20, game->GetTexture(7), game->GetTexture(8), this, color));
					break;
				case 1:
					objects.push_back(new BigArrows(Point2D(0, 0), Vector2D(0, 0), 20, 20, game->GetTexture(7), game->GetTexture(8), this, color));
					break;

				}
				eventHandler.push_back(dynamic_cast<EventHandler*>(objects.back()));
			}
			else
			{
				throw FileFormatError("Formato de archivo incorrecto");
			}
			dynamic_cast<ArrowsGameObject*>(objects.back())->loadFromFile(input);
			dynamic_cast<ArrowsGameObject*>(objects.back())->setItList(--objects.end());
		}
	}
	input.close();
}

void PlayState::AddArrows(int arrows)
{
	NUM_FLECHAS += arrows;
	scoreboard->Arrows(NUM_FLECHAS);
}
void PlayState::ArrowSize(double prop)
{
	arrowsSize += prop;
}