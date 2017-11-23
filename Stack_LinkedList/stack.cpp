#include "stack.h"
#include<iostream>
using namespace std;


void stack::stack_Add(int item)
{
	stack *element = new stack[stack_size];
	if (element_number >= stack_size)
	{
		cout << endl;
		cout << "> Stack is full !" << endl;
		return;
	}
	if (last != NULL)
	{
		last->pnext = element;
		element->pprev = last;
		element->value = item;
		last = element;
		last->pnext = NULL;
		element_number++;
	}
	else
	{
		head = element;
		last = element;
		element->value = item;
		head->pnext = NULL;
		head->pprev = NULL;
		element_number++;
	}
}
void stack::stack_List()
{
	stack *element;
	element = head;
	if (element == NULL)
	{
		cout << "> Stack is empty ! " << endl;
	}
	else
	{
		while (element)
		{
			cout << element->value << " ";
			element = element->pnext;
		}
	}
}
void stack::stack_Delete()
{
	stack *element;
	element = last;
	if (last == NULL)
	{
		cout << "> Stack is empty !" << endl;
	}
	else if (head == last)
	{
		cout << "> Deleting element -> " << last->value << endl;
		head = NULL;
		last = NULL;
		element_number = element_number - 1;
	}
	else
	{
		cout << "> Deleting element -> " << last->value << endl;
		last = last->pprev;
		last->pnext = NULL;
		element_number = element_number - 1;
	}
}
void stack::stack_Count()
{
	int count = 0;
	stack *element;
	element = head;

	while (element)
	{
		count++;
		element = element->pnext;
	}
	
	cout << "> The number of elements in the stack -> " << count << endl;
}
