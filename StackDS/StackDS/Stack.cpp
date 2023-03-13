#include "Stack.h"
#include<iostream>
using namespace std;

Stack::Stack()
{
	cout << "Empty stack is created!" << std::endl;
}

Stack::~Stack()
{
	m_elements.erase(m_elements.begin(), m_elements.end());
	cout << "All elements erased and stack is destroyed!" << std::endl;
}

int Stack::get_size() const {
	return m_elements.size();
}

void Stack::push(int val) {
	m_elements.insert(m_elements.begin(), val);
	cout << "Element " << val << " pushed!" << std::endl;
}

int Stack::pop() {
	if (!m_elements.empty()) {
		int val = m_elements.front();
		m_elements.erase(m_elements.begin());
		cout << "Element " << val << " popped!" << std::endl;
		return val;
	}
	else {
		cout << "Stack is empty!" << std::endl;
	}
}

bool Stack::isEmpty()
{
	return m_elements.empty();

}