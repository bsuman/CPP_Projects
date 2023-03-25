#include<iostream>
#include"ParkingSystem.h"
using namespace std;

int main() {
	ParkingSystem *ptr_ps = new ParkingSystem(1, 1, 0);
	string canpark = ptr_ps->addCar(1) ? "Yes" : "No";
	cout << " Can the car park ? " << canpark << endl;
	canpark = ptr_ps->addCar(2) ? "Yes" : "No";
	cout << " Can the car park ? " << canpark << endl;
	canpark = ptr_ps->addCar(3) ? "Yes" : "No";
	cout <<" Can the car park ? " << canpark << endl;
	canpark = ptr_ps->addCar(4) ? "Yes" : "No";
	cout << " Can the car park ? " << canpark << endl;
	canpark = ptr_ps->addCar(1) ? "Yes" : "No";
	cout << " Can the car park ? " << canpark << endl;
	return 0;
}