#pragma once
#include<vector>
#include<iostream>
#include"Heap.h"
using namespace std;

template<typename T>
class MinHeap :public Heap<T> {
	vector<T> heap;

protected:
	void heapify_up(int index)
	{
		while (true)
		{
			int parent_index = (index - 1) / 2;
			if (parent_index >= 0 and heap[parent_index] > heap[index])
			{
				T tmp = heap[index];
				heap[index] = heap[parent_index];
				heap[parent_index] = tmp;
				index = parent_index;
			}
			else
				break;
		}

	}

	void heapify_down()
	{
		int index(0), hs(heap.size());
		while (true)
		{
			int left = 2 * index + 1;
			int right = 2 * index + 2;
			int minIndex = index;
			if (left < hs && heap[left] < heap[minIndex])
			{
				minIndex = left;
			}
			if (right < hs && heap[right] < heap[minIndex])
			{
				minIndex = right;
			}
			if (minIndex != index)
			{
				T tmp = heap[minIndex];
				heap[minIndex] = heap[index];
				heap[index] = tmp;
				index = minIndex;
			}
			else {
				break;
			}
		}
	}

public:
	MinHeap() {

	}
	
	~MinHeap() {
		heap.clear();
	}
	
	
	void push(T val)
	{
		heap.push_back(val);
		int index = heap.size();
		heapify_up(index - 1);
	}

	T pop()
	{
		if (heap.size() == 1)
		{
			T tmp = heap.back();
			heap.pop_back();
			return tmp;
		}
		else if(heap.size()>1)
		{
			T tmp = heap[0];
			heap[0] = heap.back();
			heap.pop_back();
			heapify_down();
			return tmp;
		}
		else {
			return -1;
		}
	}


	T peek()
	{
		if(heap.size()>=1){
			T tmp = heap[0];
			return tmp;
		}
		else{
			return -1;
		}
	}
};