// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"

int main()
{
	llist l;
	l.insertNode(10);
	l.insertNode(12);
	l.insertNode(13);
	l.displayList();
	l.deleteData(12);
	l.displayList();

    return 0;
}

