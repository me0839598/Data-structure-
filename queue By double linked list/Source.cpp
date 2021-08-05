
#include <iostream>
#include <iomanip>
#include<stdio.h>
#include<conio.h>
using std::setfill;
using std::setw;
using std::cout;
using std::cin;
using std::endl;
float getavg(float);



struct node
{
	node *prev;
	int data;
	node *next;
};

struct quee
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

quee* EnQuee(quee* Myquee, node* newnode)
{
	if (Myquee->count == 0)
	{
		Myquee->first = newnode;
		Myquee->last = newnode;
		Myquee->count = 1;
		cout << "Insert item at first in empty list  \n";
	}

	else
	{
		Myquee->last->prev = newnode;
		newnode->next = Myquee->last;
		Myquee->last = Myquee->last->prev;
		Myquee->count = Myquee->count + 1;
		cout << "Insert item at last  \n";
	}

	return Myquee;
}

quee* DeQuee(quee* Myquee)
{

	node* ptr;
	if (Myquee->count == 0)
	{
		cout << "  \n";
		cout << " Empty quee \n";
		cout << "  \n";
	}
	else if (Myquee->count == 1)
	{
		cout << "  \n";
		cout << "The returned value is  " << Myquee->first->data;
		cout << "  \n";
		ptr = Myquee->first;
		Myquee->first = NULL;
		delete(ptr);
		Myquee->count = Myquee->count - 1;
	}
	else
	{
		cout << "  \n";
		cout << "The deleted value is  " << Myquee->first->data;
		cout << "  \n";
		ptr = Myquee->first;

		Myquee->first = Myquee->first->prev;
		//Myquee->first->next=NULL;
		delete(ptr);

		Myquee->count = Myquee->count - 1;
	}
	return Myquee;
}

void PrintList(quee* Myquee)
{
	node* ptr;
	ptr = Myquee->first;
	cout << " \n";
	if (Myquee->count != 0)
	{
		cout << "The List contains : ";
		while (ptr != NULL)
		{
			cout << " " << ptr->data;
			ptr = ptr->prev;
		}
		cout << "  The number of nodes : " << Myquee->count;
	}
	else
		cout << "The list is empty...";
	cout << " \n \n";
}

int main()
{
	int val;
	quee* Myquee = new quee();



	//Myquee->count=0;
	//Myquee->first=NULL;
	//Myquee->last=NULL;
	char choice;

	do{
		cout << "\na- enQuee.\nd- deQuee.\np- Print All.\ne- Exit.\n";
		cout << "\nEnter Your Choice: ";
		cin >> choice;

		switch (choice)
		{

		case ('a') :
		case ('A') :
		{
					   node* newnode = createNode();
					   Myquee = EnQuee(Myquee, newnode);
		}
				   break;
		case 'd':
		case 'D':
		{

					Myquee = DeQuee(Myquee);

		}
			break;
		case 'P':
		case 'p':
		{
					PrintList(Myquee);
		}
			break;
		}
	} while (choice != 'e');

}
