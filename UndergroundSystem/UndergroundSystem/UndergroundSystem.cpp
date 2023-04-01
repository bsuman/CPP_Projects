#include"UndergroundSystem.h"

UndergroundSystem::UndergroundSystem() {

}

UndergroundSystem::~UndergroundSystem() {
	checkout_playerId_station.clear();
	checkin_playerId_station.clear();
	set_player_id.clear();
}


void UndergroundSystem::checkIn(int id, string stationName, int t) {	
	string key(stationName + to_string(id));
	if (checkin_playerId_station.find(key) != checkin_playerId_station.end())
	{
		checkin_playerId_station[key].push_back(t);
		
	}
	else {
		checkin_playerId_station.insert({ key, { t } });
	}
	set_player_id.insert(id);
}

void UndergroundSystem::checkOut(int id, string stationName, int t) {
	string key(stationName + to_string(id));
	if (checkout_playerId_station.find(key) != checkout_playerId_station.end())
	{
		checkout_playerId_station[key].push_back(t);

	}
	else {
		checkout_playerId_station.insert({ key, { t } });
	}
}

double UndergroundSystem::getAverageTime(string startStation, string endStation) {
	double averageTime = 0.0, sum = 0.0;
	int numTravelTime = 0;
	for (auto player_id : set_player_id)
	{
		string key_checkin(startStation + to_string(player_id));
		string key_checkout(endStation + to_string(player_id));

		if(checkin_playerId_station.find(key_checkin) != checkin_playerId_station.end()
			&& checkout_playerId_station.find(key_checkout) != checkout_playerId_station.end())
		{
			vector<int> checkinTimes = checkin_playerId_station[key_checkin];
			vector<int> checkoutTimes = checkout_playerId_station[key_checkout];
			if (checkinTimes.size() == checkoutTimes.size())
			{
				for (size_t index = 0; index < checkinTimes.size(); index++) {
					sum = sum+ (checkoutTimes[index] - checkinTimes[index]);
					numTravelTime++;
				}
			}
		}
	}
	if (numTravelTime > 0) {
		averageTime = sum / numTravelTime;
	}
	return averageTime;

}