#ifndef SCORESH
#define SCORESH
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Scores
{
private:
	struct ScoreReg
	{
		string name;
		int score;
	};
	vector<ScoreReg*>TopScores;
	

public:
	const int numPuntuaciones = 10;
	void Load(const string& filename);
	void printTopNScores(int n);
	void addScore(const string& name, int score);
	void save(const string& name);
	private:
	void mergesort(vector<ScoreReg*>& v, int ini, int fin);
	void merge(vector<ScoreReg*>& v, int l, int m, int r);
};
#endif

