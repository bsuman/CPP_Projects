#include"BrowserHistory.h"
#include<iostream>
/*
You have a browser of one tab where you start on the homepage and you can visit another url, 
get back in the history number of steps or move forward in the history number of steps.
*/

int main() {

	BrowserHistory brow_his("leetcode.com");
	brow_his.visit("google.com");
	brow_his.visit("facebook.com");
	brow_his.visit("youtube.com");

	cout<<" Back 1 step: "<< brow_his.back(1) << endl;
	cout<<" Back 1 more step: " << brow_his.back(1) << endl;
	cout << " Forward 1 step: " << brow_his.forward(1) << endl;

	brow_his.visit("linkedin.com");

	cout << " Forward 2 steps: " << brow_his.forward(2) << endl;
	cout << " Back 1 step: " << brow_his.back(2) << endl;
	cout << " Back 1 more step: " << brow_his.back(7) << endl;




	BrowserHistory brow_his_2("esgriv.com");
	brow_his_2.visit("cgrt.com");
	brow_his_2.visit("tip.com");

	cout << " Back 9 step: " << brow_his_2.back(9) << endl;

	brow_his_2.visit("kttzxgh.com");

	cout << " Forward 7 step: " << brow_his_2.forward(7) << endl;

	brow_his_2.visit("crqje.com");
	brow_his_2.visit("iybch.com");

	cout << " Forward 5 step: " << brow_his_2.forward(5) << endl;

	brow_his_2.visit("uun.com");

	cout << " Back 10 step: " << brow_his_2.back(10) << endl;

	brow_his_2.visit("hci.com");
	brow_his_2.visit("whula.com");

	cout << " Forward 10 step: " << brow_his_2.forward(10) << endl;

	return 1;
}