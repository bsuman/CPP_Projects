#pragma once
#include<vector>
#include<map>

using namespace std;
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() 

You must implement a solution with O(1) time complexity for each function.

*/
struct minVal {
    int val; 
    int minVal;
};

class MinStack {
    vector<minVal> stack;

public:
    //initializes the stack object.
    MinStack();

    virtual ~MinStack();

    //pushes the element val onto the stack.
    void push(int val);

    //removes the element on the top of the stack.
    void pop();

    //gets the top element of the stack.
    int top();

    //retrieves the minimum element in the stack.
    int getMin();
};