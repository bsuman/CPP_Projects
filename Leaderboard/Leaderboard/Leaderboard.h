#pragma once
#include<unordered_map>
#include<string>
using namespace std;

class Leaderboard {
	unordered_map<int, int> score_board;

public: 
	Leaderboard();
	virtual ~Leaderboard();

	void addScore(int playerId, int score);
	int top(int K);
	void reset(int playerId);

};