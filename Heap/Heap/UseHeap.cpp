#include"MinHeap.h"
#include"MaxHeap.h"
#include<iostream>

int main() {
	MinHeap<int> minH;
	minH.push(10);
	minH.push(12);
	minH.push(3);
	minH.push(30);
	minH.push(20);
	minH.push(1);
	int tmp_i = minH.pop();
	while(tmp_i !=-1)
	{
		cout << "Popped Element " << tmp_i << endl;
		tmp_i = minH.pop();
	}
	cout << "===========MinHeap=============" << endl;
	MinHeap<double> minH_d;
	minH_d.push(1.2);
	minH_d.push(22.2);
	minH_d.push(3.1);
	minH_d.push(31.4);
	minH_d.push(2.1);
	minH_d.push(0);
	double tmp_d = minH_d.pop();
	while (tmp_d != -1)
	{
		cout << "Popped Element " << tmp_d << endl;
		tmp_d = minH_d.pop();
	}
	cout << "===========MaxHeap=============" << endl;
	MaxHeap<int> maxH;
	maxH.push(10);
	maxH.push(12);
	maxH.push(3);
	maxH.push(30);
	maxH.push(20);
	maxH.push(1);
	int tmp = maxH.pop();
	while (tmp != -1)
	{
		cout << "Popped Element " << tmp << endl;
		tmp = maxH.pop();
	}
	return 0;
}