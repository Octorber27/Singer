/*--List.h--*/
#pragma once
#include"Singer.h"
class List
{
	Singer *head = NULL;
public:
	~List();
	void CreateList();
	Singer* SortList();
	void Print();
	void PrintList();
};