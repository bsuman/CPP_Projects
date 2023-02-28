// Given an array of integers nums sorted in non - decreasing order, find the startingand ending position of a given target value.
// If target is not found in the array, return[-1, -1].
// You must write an algorithm with O(log n) runtime complexity.
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int binarysearch(int low, int high, vector<int>& nums, int target)
{
    if (high < low)
        return -1;

    int mid = -1;
    mid = (low + high) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] < target)
        return binarysearch(mid + 1, high, nums, target);
    else
        return binarysearch(low, mid - 1, nums, target);
}

vector<int> searchRange(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    vector<int> temp;
    int start = binarysearch(low, high, nums, target);
    if (start == -1)
    {
        temp.push_back(start);
        temp.push_back(start);
        return temp;
    }
    else
    {
        int endindex = start;
        while (endindex < high)
        {
            if (nums[endindex + 1] == target)
                endindex++;
            else
                break;
        }
        int startindex = start;
        while (startindex > low)
        {
            if (nums[startindex - 1] == target)
                startindex--;
            else
                break;
        }
        temp.push_back(startindex);
        temp.push_back(endindex);
        return temp;
    }
}

int main()
{
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;
	vector<int> result = searchRange(nums, target);
    for_each(result.begin(), result.end(), [] (const int n) { cout << n << endl; });
    cout << "\n";

	return 0;
}