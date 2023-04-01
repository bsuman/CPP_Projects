// Leaderboard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"Leaderboard.h"
#include<algorithm>
#include<vector>
Leaderboard::Leaderboard() {

}

Leaderboard::~Leaderboard() {
	score_board.clear();
}

void Leaderboard::addScore(int playerId, int score) {
	if (score_board.find(playerId) != score_board.end()) {
		score_board[playerId] = score_board[playerId] + score;
	}
	else {
		score_board.insert({ playerId, score });
	}
}

int Leaderboard::top(int K) {
	int t = 0;
	vector<pair<int, int> > mapcopy(score_board.begin(), score_board.end());
	struct greater_second {
		bool operator ()(pair<int, int> const& a, pair<int, int> const& b) const {
			return a.second > b.second;
		}
	};

	sort(mapcopy.begin(), mapcopy.end(), greater_second());
	int sum_score = 0;
	for(int index = 0;index< K; index++)
	{
		sum_score += mapcopy[index].second;
	}
	return sum_score;
}

void Leaderboard::reset(int playerId) {
	if (score_board.find(playerId) != score_board.end()) {
		score_board[playerId] = 0;
	}
}