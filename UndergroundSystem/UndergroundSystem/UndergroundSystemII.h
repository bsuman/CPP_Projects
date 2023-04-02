#pragma once
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

class Data {
public:
	string checkin_station;
	string checkout_station;
	int checkin_t;
	int checkout_t;
};

class UndergroundSystemII {
	unordered_map<string, vector<int>> station_average_time;
	unordered_map<int, Data> playerId_TravelInfo;

public:
	virtual ~UndergroundSystemII();
	UndergroundSystemII();
	void checkIn(int id, string stationName, int t);
	void checkOut(int id, string stationName, int t);
	double getAverageTime(string startStation, string endStation);
};