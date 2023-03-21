// ArrayIndexAndElementEquality.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int indexEqualsValueSearch(const vector<int>& arr)
{
    int arrsize = arr.size();
    int low{ 0 }, high{ arrsize - 1 };
    while (low+1 < high) {
        int mid = (high + low) / 2;
        if (arr[mid] >= mid)
           high =  mid;
        else
           low = mid;
    }
    if(arr[high] == high)
        return high;
    else
        return -1;
}


int main()
{
    vector<int> arr{ -8, 0, 2, 5 };
    cout << "Element found at postion: " << indexEqualsValueSearch(arr) << endl;
    vector<int> arr1{ -1, 0, 3, 6 };
    cout << "Element found at postion: " << indexEqualsValueSearch(arr1) << endl;

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
