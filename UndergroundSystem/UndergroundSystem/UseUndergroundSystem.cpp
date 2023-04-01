#include"UndergroundSystem.h"
#include<iostream>

int main() {
	UndergroundSystem us;
	us.checkIn(45, "Leyton", 3);
	us.checkIn(32, "Paradise", 8);
	us.checkIn(27, "Leyton", 10);
	us.checkOut(45, "Waterloo", 15);
	us.checkOut(27, "Waterloo", 20);
	us.checkOut(32, "Cambridge", 22);
	cout<<"Average time from Paradise to Cambridge is " << us.getAverageTime("Paradise", "Cambridge") << endl;
	cout << "Average time from Leyton to Waterloo is " << us.getAverageTime("Leyton", "Waterloo") << endl;
	us.checkIn(10, "Leyton", 24);
	cout << "Average time from Leyton to Waterloo is " << us.getAverageTime("Leyton", "Waterloo") << endl;
	us.checkOut(10, "Waterloo", 38);
	cout << "Average time from Leyton to Waterloo is " << us.getAverageTime("Leyton", "Waterloo") << endl;

	UndergroundSystem uss;
	uss.checkIn(10, "Leyton", 3);
	uss.checkOut(10, "Paradise", 8);
	cout << "Average time from Leyton to Paradise is " << uss.getAverageTime("Leyton", "Paradise") << endl;
	uss.checkIn(5, "Leyton", 10);
	uss.checkOut(5, "Paradise", 16);
	cout << "Average time from Leyton to Paradise is " << uss.getAverageTime("Leyton", "Paradise") << endl;
	uss.checkIn(2, "Leyton", 21);
	uss.checkOut(2, "Paradise", 30);
	cout << "Average time from Leyton to Paradise is " << uss.getAverageTime("Leyton", "Paradise") << endl;

	return 1;
}