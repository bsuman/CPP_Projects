#include"MinStack.h"
#include<iostream>
#include<algorithm>

using namespace std;

//initializes the stack object.
MinStack::MinStack() {

}

MinStack:: ~MinStack() {
	stack.clear();
}

//pushes the element val onto the stack.
void MinStack::push(int val) {
	minVal mv, tmp;
	if (stack.size() == 0) {
		tmp.val = val;
		tmp.minVal = val;
	}
	else {
		mv = stack[0];
		tmp.val = val;
		tmp.minVal = val;
		if (mv.minVal < val) {
			tmp.minVal = mv.minVal;
		}
	}
	stack.insert(stack.begin(), tmp);
}

//removes the element on the top of the stack.
void MinStack::pop() {
	if(stack.size()>= 1) {
		stack.erase(stack.begin());
	}	
}

//gets the top element of the stack.
int MinStack::top() {
	if (stack.size() >= 1) {
		return stack[0].val;
	}
}

//retrieves the minimum element in the stack.
int MinStack::getMin() {
	return stack[0].minVal;
}






