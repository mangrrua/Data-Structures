#pragma once
#include<iostream>
using namespace std;

class stack
{
private:
	int element_number = 0;
	int value;
	stack *pprev;
	stack *pnext;
	stack *head = NULL;
	stack *last = NULL;
public:
	int stack_size;
	void stack_Add(int item);
	void stack_Delete();
	void stack_List();
	void stack_Count();
};

