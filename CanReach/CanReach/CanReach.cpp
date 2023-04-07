// CanReach.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

string canReach(int x1, int y1, int x2, int y2) {
    // queue of possible moves
    vector<pair<int, int>> points;
    unordered_map<string, bool> visited;
    // push the start point to moves
    points.push_back({ x1,y1 });
    // keep going until there possible moves
    while (points.size() > 0) {
        pair<int, int> point = points[0];
        // remove the point from the list
        points.erase(points.begin());
        int p1_x = point.first;
        int p1_y = point.second;
        string key = to_string(p1_x) +"_" + to_string(p1_y);
        while (visited.find(key) == visited.end()) {
            // check if we reached the destination, if true, return yes
            if (p1_x == x2 && p1_y == y2) {
                return "Yes";
            }
            else {
                // else possible moves are : 
                // moving up
                visited[key] = "true";
                if (p1_x <= x2 && p1_x + p1_y <= y2) {
                    points.push_back({ p1_x,p1_x + p1_y });
                }
                // moving right
                if (p1_x + p1_y <= x2 && p1_y <= y2) {
                    points.push_back({ p1_x + p1_y, p1_y });
                }
            }
        }
    }

    return "No";
}


int main()
{
    int x1 = 1;
    int y1 = 4;
    int x2 = 62;
    int y2 = 45;
    

    cout << canReach(x1, y1, x2, y2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
