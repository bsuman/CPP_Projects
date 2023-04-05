// VectorEras.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<vector>
#include <iostream>
using namespace std;


void erase(int start, int end,vector<int>& input) {
    start--;
    end--;
    if (start >= 0 && end < input.size()) {
        input.erase(input.begin() + start, input.begin() + end);
    }
}


void erase(int pos, vector<int>& input) {
    pos--;
    if (pos >= 0 && pos <= input.size() - 1) {
        input.erase(input.begin() + pos);
    }
}

int main()
{
    vector<int> input{1,4,6,2,8,9};
    erase(2, input);
    erase(2,4, input);
    cout << "Size of the vector" << input.size() << endl;

    for (auto elem : input) {
        cout <<elem << " ";
    }
    //vector<int> input;
    //int num_element;
    //cin >> num_element;
    //int elem;
    //for (int i = 0; i < num_element; i++) {
    //    cin >> elem;
    //    input.push_back(elem);
    //}
    //int pos;
    //cin >> pos;
    //erase(pos, input);
    //int startposition;
    //cin >> startposition;

    //int endposition;
    //cin >> endposition;
    //erase(startposition, endposition, input);

    //cout << input.size() << endl;

    //for (auto elem : input) {
    //    cout << elem << " ";
    //}

    return 0;
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
