#include"MinStack.h"
#include<iostream>
using namespace std;
int main() {
	MinStack ms;
	ms.push(-2);
	ms.push(0);
	ms.push(-3);
	cout<< "Get Min: " << ms.getMin() <<endl;
	ms.pop();
	cout << "Get Top: " << ms.top() << endl;
	cout << "Get Min: " << ms.getMin() << endl;
	return 1;
}