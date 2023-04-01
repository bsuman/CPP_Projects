#pragma once
#include<string>
#include<unordered_map>
#include<set>
using namespace std;

class UndergroundSystem {
	unordered_map<string, vector<int>> checkin_playerId_station;
	unordered_map<string, vector<int>> checkout_playerId_station;
	set<int> set_player_id;

public:
	virtual ~UndergroundSystem();
	UndergroundSystem();
	void checkIn(int id, string stationName, int t);
	void checkOut(int id, string stationName, int t);
	double getAverageTime(string startStation, string endStation);
};