#pragma once
#include<vector>
using namespace std;

class Stack {
	vector<int> m_elements;

public:
	Stack();
	~Stack();
	int get_size()const;
	void push(int val);
	int pop();
	bool isEmpty();
};