
#include <iostream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::cout;
using std::cin;
using std::endl;
float getavg(float);

#include<stdio.h>
#include<conio.h>


struct node
{
	node *prev;
	int data;
	node *next;
};

struct stack
{
	node *first;
	int count;
	node *last;
};

node* createNode()
{
	node* node1 = new node();
	node1->prev = NULL;
	cout << "\nEnter the value:  ";
	cin >> node1->data;
	node1->next = NULL;
	return node1;
}

stack* push(stack* MyStack, node* newnode)
{
	if (MyStack->count == 0)
	{
		MyStack->first = newnode;
		MyStack->last = newnode;
		MyStack->count = 1;
		cout << "Insert item at first in empty list  \n";
	}

	else
	{
		MyStack->last->next = newnode;
		newnode->prev = MyStack->last;
		MyStack->last = MyStack->last->next;
		MyStack->count = MyStack->count + 1;
		cout << "Insert item at last  \n";
	}

	return MyStack;
}

stack* pop(stack* Mystack)
{

	node* ptr;
	if (Mystack->count == 0)
	{
		cout << "  \n";
		cout << " Empty Stack \n";
		cout << "  \n";
	}
	else if (Mystack->count == 1)
	{
		cout << "  \n";
		cout << "The returned value is  " << Mystack->last->data;
		cout << "  \n";
		ptr = Mystack->last;
		Mystack->last = NULL;
		delete(ptr);
		Mystack->count = Mystack->count - 1;
	}
	else
	{
		cout << "  \n";
		cout << "The returned value is  " << Mystack->last->data;
		cout << "  \n";
		ptr = Mystack->last;
		Mystack->last = Mystack->last->prev;
		Mystack->last->next = NULL;
		delete(ptr);

		Mystack->count = Mystack->count - 1;
	}
	return Mystack;
}

void PrintList(stack* MyStack)
{
	node* ptr;
	ptr = MyStack->first;
	cout << " \n";
	if (MyStack->count != 0)
	{
		cout << "The List contains : ";
		while (ptr != NULL)
		{
			cout << " " << ptr->data;
			ptr = ptr->next;
		}
		cout << "  The number of nodes : " << MyStack->count;
	}
	else
		cout << "The list is empty...";
	cout << " \n \n";
}

int main()
{
	int val;
	stack* MyStack = new stack();



	//MyStack->count=0;
	//MyStack->first=NULL;
	//MyStack->last=NULL;
	char choice;

	do{
		cout << "\na- push.\nd- pop.\np- Print All.\ne- Exit.\n";
		cout << "\nEnter Your Choice: ";
		cin >> choice;

		switch (choice)
		{

		case ('a') :
		case ('A') :
		{
					   node* newnode = createNode();
					   MyStack = push(MyStack, newnode);
		}
				   break;
		case 'd':
		case 'D':
		{

					MyStack = pop(MyStack);

		}
			break;
		case 'P':
		case 'p':
		{
					PrintList(MyStack);
		}
			break;
		}
	} while (choice != 'e');

}
