// FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

/*
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
*/

vector<string> fizzBuzz(int n) {
    vector<string> answer;
    for (auto i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            answer.push_back("FizzBuzz");

        }
        else if(i % 3 == 0 && i % 5 != 0) {
            answer.push_back("Fizz");

        }
        else if (i % 5 == 0 && i % 3 != 0) {
            answer.push_back("Buzz");
        }
        else {
            answer.push_back(to_string(i));
        }

    }
    return answer;
}

int main()
{
    int n(15);
    vector<string> answer(fizzBuzz(n));
    for (auto i : answer) {
        cout << i << endl;
    }
    
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
