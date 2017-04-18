#pragma once

struct Node
{
	int data;
	Node* next;

};

class llist
{
	Node *head;

public:

	llist():head(nullptr) {

	}

	~llist()
	{


	}

	void insertNode(int data);
	void deleteData(int data);
	void displayList();


};