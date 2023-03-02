// 3Sum.cpp : 
// Given an integer array nums, return all the triplets[nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
//

#include <iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int nl(nums.size());
    sort(nums.begin(), nums.end());
    vector<vector<int>> combi;
    set<vector<int>> myset;

    for (int i = 0; i < nl - 2; i++)
    {
        for (int j = i + 1; j < nl - 1; j++)
        {
            for (int k = j + 1; k < nl; k++)
            {
                if ((nums[i] + nums[j] + nums[k] == 0) && (i != j && j != k && i != k))
                {
                    myset.insert({ nums[i], nums[j], nums[k] });
                }
            }
        }
    }
    for (auto it : myset) {
        combi.push_back(it);
    }
    return combi;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    int nl(nums.size());
    sort(nums.begin(), nums.end());
    vector<vector<int>> combi;
    set<vector<int>> myset;

    for (int i = 0; i < nl - 2; i++)
    {
        int j = i + 1, k = nl - 1;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] < 0) {
                j++;
            }
            else if (nums[i] + nums[j] + nums[k] > 0) {
                k--;
            }
            else {
                myset.insert({ nums[i], nums[j], nums[k] });
                j++;
                k--;
            }
        }
    }
    for (auto it : myset) {
        combi.push_back(it);
    }
    return combi;
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
