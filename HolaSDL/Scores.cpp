#include "Scores.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include "checkML.h"

using namespace std;


//metodos para ordenar el vector de puntuaciones
	void  Scores::merge(vector<ScoreReg*>& v, int l, int m, int r)
	{
		int i, j, k;
		int n1 = m - l;
		int n2 = r - m;
		/*Crea  variables temporales  */
		vector<ScoreReg*> L, R;
		L.reserve(n1);
		R.reserve(n2);
		// Copia los datos a los vectores L[] y R[] 
		for (i = 0; i < n1; i++)
			L.push_back(v[l + i]);
		for (j = 0; j < n2; j++)
			R.push_back(v[m + j]);
		// Merge los vectores temporales en nuestro vector v[l..r]
		i = 0; // indice del primer subvector
		j = 0;// indice del segundo subvector
		k = l;// indice del merge subvector
		while (i < n1 && j < n2)
		{
			if (L[i]->score <= R[j]->score)
			{
				v[k] = L[i];

				i++;
			}
			else
			{
				v[k] = R[j];
				j++;
			}
			k++;
		}
		//Copia los elementos restantes de L 
		while (i < n1)
		{
			v[k] = L[i];
			i++;
			k++;
		}
		// Copia los elementos restantes de R 
		while (j < n2)
		{
			v[k] = R[j];
			j++;
			k++;
		}
	}

	void Scores::mergesort(vector<ScoreReg*>& v, int ini, int fin) {

		if (ini < fin - 1) {
			int mit = (ini + fin) / 2;
			mergesort(v, ini, mit);
			mergesort(v, mit, fin);
			merge(v, ini, mit, fin);
		}
	}
	
//metodo que nos muestra en consola las mejores puntuaciones con el nombre de cada persona
void Scores:: printTopNScores(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << TopScores[i]->name + " ";
		cout << TopScores[i]->score<<endl;

	}
	
}
//metodo que añade el nombre y la puntuacion
void Scores::addScore(const string& name, int score)
{
	ScoreReg* game = new ScoreReg();
	game->name = name;
	game->score = score;
	
	TopScores.push_back(game);

	if (TopScores.size()>9)
	{
		TopScores.erase(TopScores.begin());

	}
	mergesort(TopScores,0,TopScores.size());
	printTopNScores(TopScores.size());
}

void Scores::Load(const string& filename)
{
	ifstream input;
	int num;
	char c;
	string name;
	input.open(filename);
	if (!input.is_open()) cout << "No se encuentra el fichero" << endl;
	else {
		
		input >> num;
		for (int i = 0; i < num; i++) {
			ScoreReg* game = new ScoreReg();
			input >> game->score;
			input.get(c);
			getline(input, game->name);
			TopScores.push_back(game);
		}
		input.close();
	}
}
void Scores::save(const string& filename)
{
	ofstream output;
	output.open(filename);

	if (!output.is_open()) { cout << "No se encuentra el fichero" << endl; }
	else {
		output << TopScores.size()<<endl;
		for (int i = 0; i < TopScores.size(); i++) {
			output << TopScores[i]->score;
			output<< " ";
			output<< TopScores[i]->name<<endl;

		}
		output.close();
	}
}