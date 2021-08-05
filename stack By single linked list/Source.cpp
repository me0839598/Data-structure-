#include<iostream>
#include<process.h>

using namespace std;

struct Node
{
	int data;
	Node *next;
}*top = NULL, *p;

Node* newnode()
{

	p = new Node;
	cout << "data =";
	cin >> p->data;
	p->next = NULL;
	return(p);
}

void push(Node *newnode)
{
	if (top == NULL)
		top = newnode;
	else
	{
		newnode->next = top;
		top = newnode;
	}
}

void pop(){
	if (top == NULL){
		cout << "Stack is empty!!";
	}
	else{
		cout << "Deleted element is " << top->data;
		p = top;
		top = top->next;
		delete(p);
	}
}

void showstack()
{
	Node *q;
	q = top;

	if (top == NULL){
		cout << "Stack is empty!!";
	}
	else{
		while (q != NULL)
		{
			cout << q->data << endl;
			q = q->next;
		}
	}
}

int main()
{
	char ch;
	//int x;
	Node *p;

	do
	{
		cout << "\n\na.Push\nd.Pop\np.Display\ne.Exit";
		cout << "\nEnter your choice:";
		cin >> ch;

		switch (ch){
		case 'a': //cout<<"\nEnter data:";
			//cin>>x;
			p = newnode();
			push(p);
			break;

		case 'd':
			pop();
			break;

		case 'p':
			showstack();
			break;



		}
	} while (ch != 'e');

	return 0;
}
