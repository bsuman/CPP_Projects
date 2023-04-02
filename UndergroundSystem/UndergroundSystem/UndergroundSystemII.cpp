#include"UndergroundSystemII.h"
#include<numeric>

UndergroundSystemII::UndergroundSystemII() {



}

UndergroundSystemII::~UndergroundSystemII() {
	station_average_time.clear();
	playerId_TravelInfo.clear();
}


void UndergroundSystemII::checkIn(int id, string stationName, int t) {
	Data info;
	info.checkin_station = stationName;
	info.checkin_t = t;
	playerId_TravelInfo[id] = info;
}

void UndergroundSystemII::checkOut(int id, string stationName, int t) {
	Data info(playerId_TravelInfo[id]);
	info.checkout_station = stationName;
	info.checkout_t = t;
	station_average_time[info.checkin_station+"->" + info.checkout_station].push_back(info.checkout_t - info.checkin_t);
}

double UndergroundSystemII::getAverageTime(string startStation, string endStation) {
	vector<int> timeValues = station_average_time[startStation + "->" + endStation];
	double sum = accumulate(timeValues.begin(), timeValues.end(),0);
	return (sum / timeValues.size());
}