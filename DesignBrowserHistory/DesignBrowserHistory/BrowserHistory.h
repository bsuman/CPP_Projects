#pragma once
#include<string>
#include<vector>

using namespace std;

class BrowserHistory {

    vector<string> pages;
    int curr_index = 0;

public:
    /*
    * Initializes the object with the homepage of the browser.
    */
    BrowserHistory(string homepage);

    virtual ~BrowserHistory();
    /*
    * Visits url from the current page. It clears up all the forward history.
    */
    void visit(string url);
    
    /*
    * Move steps back in history. 
    * If you can only return x steps in the history and steps > x, you will return only x steps.
    * Return the current url after moving back in history at most steps.
    */
    string back(int steps);

    /*
    * Move steps forward in history. 
    * If you can only forward x steps in the history and steps > x, you will forward only x steps.
    * Return the current url after forwarding in history at most steps.
    */
    string forward(int steps);
};