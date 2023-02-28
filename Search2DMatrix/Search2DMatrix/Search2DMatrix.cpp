/*
Search2DMatrix.cpp : You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

#include <iostream>
#include<vector>
using namespace std;

int binarySearch(int low, int high, vector<int> matrix, int target)
{
    if (high < low) {
        return -1;
    }
    int mid = (high + low) / 2;
    if (matrix[mid] == target) {
        return mid;
    }
    if (matrix[mid] > target) {
        return binarySearch(low, mid - 1, matrix, target);
    }
    else {
        return binarySearch(mid+1,high, matrix, target);
    }

}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int result = 0;

    for (int num_row = 0; num_row < matrix.size(); num_row++) {
        
        if (target <= matrix[num_row][matrix[num_row].size()-1])
        {
            result = binarySearch(0, matrix[num_row].size(), matrix[num_row], target);
           if (result == -1)
               return false;
           else 
               return true;
        }

    }
    return false;
}


int main()
{
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 13;
    if (searchMatrix(matrix, target))
    {
        std::cout << "Element found" << endl;
    }
    else
        std::cout << "Element not found " << endl;
    
}

