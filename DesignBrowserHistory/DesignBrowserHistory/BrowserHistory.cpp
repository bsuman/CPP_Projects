#include"BrowserHistory.h"


/*
* Initializes the object with the homepage of the browser.
*/
BrowserHistory::BrowserHistory(string homepage) {
	pages.push_back(homepage);
	curr_index = pages.size()-1;
}

BrowserHistory::~BrowserHistory() {
	pages.clear();
}

void BrowserHistory::visit(string url) {
	if (curr_index == pages.size()-1)
	{
		pages.push_back(url);
		curr_index = pages.size() - 1;
	}
	else {
		curr_index += 1;
	    pages[curr_index] = url;
	}
	int numTimes = (pages.size() - 1) - curr_index;
	while(numTimes>0){
		pages.pop_back();
		numTimes--;
	}
}

string BrowserHistory::back(int steps) {
	if (curr_index - steps >= 0)
	{
		curr_index -= steps;
	}
	else {
		curr_index = 0;
	}
	return pages[curr_index];
}

string BrowserHistory::forward(int steps) {
	if (curr_index + steps <= pages.size()-1)
	{
		curr_index += steps;
	}
	else {
		curr_index = pages.size()-1;
	}
	return pages[curr_index];
}