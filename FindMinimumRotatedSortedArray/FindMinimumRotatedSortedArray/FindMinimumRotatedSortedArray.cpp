/*
FindMinimumRotatedSortedArray.cpp : This file contains the 'main' function.Program execution begins and ends there.
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

*/ 

#include <iostream>
#include <vector>
using namespace std;

enum Color { red, green, blue };

int findMin(vector<int>& nums) {
    
    if (nums.size() == 1)
        return nums[0];

    int  left = 0, right = nums.size()-1;
    if (nums[left] < nums[right])
    {
        return nums[0];
    }
    
    
    while (left < right)
    {
       int mid = (left + right) / 2;
       if (nums[mid]< nums[right]) {
           right = mid;
       }
       else{
           left = mid + 1;
       }
    }
    return nums[left];
}


int main()
{
   // vector<int> nums = { 5,1,2,3,4 };
    //int num = findMin(nums);
    //cout << "minimum number " << num;
    int tmp = red;
    cout << tmp;
};

