/* 
FindElementInRotatedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k(1 <= k < nums.length) such that the resulting array is[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]](0 - indexed).
For example, [0, 1, 2, 4, 5, 6, 7] might be rotated at pivot index 3 and become[4, 5, 6, 7, 0, 1, 2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>
using namespace std;

int binarysearch(int low, int high, vector<int>& nums, const int target) {
    if (high < low) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }
    else {
        if (nums[low] <= nums[mid]) {
            if (nums[mid] < target || target < nums[low])
                return binarysearch(mid + 1, high, nums, target);
            else 
                return binarysearch(low, mid - 1, nums, target);
        }
        else {
            if (nums[mid] > target || target > nums[high])
                return binarysearch(low, mid - 1, nums, target);
            else
                return binarysearch(mid + 1,high , nums, target);
        }
    }

}

int search(vector<int>& nums, int target) {

    int low = 0, high = nums.size() - 1;
    int found = binarysearch(low, high, nums, target);
        return found;

}


int main()
{
    vector<int> nums = { 3,5,1 };
    int target = 3;
    int index = search(nums, target);

    std::cout << "Element found at index " << index << endl;
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
