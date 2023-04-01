#pragma once

template<typename T>
class Heap {

protected:
	virtual void heapify_up(int index) = 0;
	virtual void heapify_down() = 0;

public:
	virtual void push(T val) = 0;
	virtual T pop() = 0;
	virtual T peek() = 0;
};	