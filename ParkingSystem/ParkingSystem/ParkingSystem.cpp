#include"ParkingSystem.h"
#include<iostream>
using namespace std;

ParkingSystem::ParkingSystem() :num_big(0), num_medium(0), num_small(0) {
	cout << "Parking System with following slots created !" << endl;
	cout << "#big parking: " << num_big << " #medium parking: " << num_medium << " #small parking " << num_small << endl;
}

ParkingSystem::ParkingSystem(int nbig, int nmedium, int nsmall):num_big(nbig), num_medium(nmedium), num_small(nsmall) {
	cout << "Parking System with following slots created !" << endl;
	cout << "#big parking: " << num_big << " #medium parking: " << num_medium << " #small parking " << num_small << endl;
}


bool ParkingSystem::addCar(int carType) {
	switch (carType) {
		case 3:
			if (this->num_small > 0) {
				this->num_small--;
				return true;
			}
			else {
				return false;
			}
		case 2:
			if (this->num_medium > 0) {
				this->num_medium--;
				return true;
			}
			else{
				return false;
			}

		case 1:
			if (this->num_big > 0) {
				this->num_big--;
				return true;
			}
			else {
				return false;
			}
		default:
			cout << "Invalid Car Type:" << carType << endl;	
			return false;

	}
}
