#pragma once
#include"Heap.h"
#include<iostream>
#include<vector>
using namespace std;

template<typename T> 
class MaxHeap :public Heap<T> {
	vector<T> heap;
protected: 
	void heapify_up(int index){
		int parent_index(0);
		while (true) {
			parent_index = (index - 1) / 2;
			if (parent_index >= 0 && heap[parent_index] < heap[index]) {
				T tmp = heap[index];
				heap[index] = heap[parent_index];
				heap[parent_index] = tmp;
				index = parent_index;
			}
			else {
				break;
			}

		}
	}

	void heapify_down() {
		int index(0), left(0), right(0), minIndex(0);
		int hs = heap.size();
		while(true){
			minIndex = index;
			left = (2 * index) + 1;
			right = (2 * index) + 2;
			if (left < hs && heap[left] > heap[minIndex]) {
				minIndex = left;
			}
			if (right < hs && heap[right] > heap[minIndex]) {
				minIndex = right;
			}
			if (minIndex != index) {
				T item = heap[minIndex];
				heap[minIndex] = heap[index];
				heap[index] = item;
				index = minIndex;
			}
			else {
				break;
			}
		}
	}

public:
	MaxHeap() {

	}

	~MaxHeap() {
		heap.clear();
	}

	void push(T value) {
		heap.push_back(value);
		heapify_up(heap.size()-1);
	}

	T pop() {
		if (heap.size() == 0) {
			return -1;
		}
		else if(heap.size()== 1) {
			T item = heap.back();
			heap.pop_back();
			return item;
		}
		else {
			T item = heap[0];
			heap[0] = heap.back();
			heap.pop_back();
			heapify_down();
			return item;
		}

	}

	T peek() {
		if (heap.size() > 0) {
			return heap[0];
		}
		else {
			cout << "Heap Empty!";
			return -1;
		}
	}

};
