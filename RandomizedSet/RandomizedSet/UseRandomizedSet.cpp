#include<iostream>
#include"RandomizedSet.h"
using namespace std;

void printmsg(bool param_1, int val, string methodname) {
	if (param_1) {
		cout << methodname << " method for val " << val << " successfull" << endl;
	}
	else {
		cout << methodname << " method for val " << val << " failed" << endl;
	}
}

int main() {
	RandomizedSet* rs = new RandomizedSet();

	int val = 1;
	bool param_1 = rs->insert(val);
	string methodname = "Insertion";
	printmsg(param_1, val, methodname);

	val = 2;
	param_1 = rs->insert(val);
	printmsg(param_1, val, methodname);

	val = 2;
	param_1 = rs->insert(val);
	printmsg(param_1, val, methodname);

	methodname = "getRandom";
	int param_3 = rs->getRandom();
	printmsg(param_3, param_3, methodname);

	val = 1;
	methodname = "remove";
	bool param_2 = rs->remove(1);
	printmsg(param_2, val, methodname);

	int val2 = rs->getRandom();
	methodname = "getRandom";
	printmsg(val2, val2, methodname);
	delete rs;


	return 0;
}
