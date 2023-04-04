// GenerateParantheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

void compute_valid_combination(string start, vector<string>& queue, vector<string>& output) {
    



}


vector<string> generateParenthesis(int n) {
    if (n == 1) {
        return { "()" };
    }
    else {
        vector<string> queue;
        vector<string> output;
        string start;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) {
                start.append("(");
            }
            else {
                start.append(")");
            }
        }
        queue.push_back(start);
        while (queue.size() > 0) {
            start = queue.front();
            compute_valid_combination(start, queue, output);
        }
        return output;
    }



}

int main()
{
    cout << "Hello World!\n";
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
