#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
}
*front = NULL, *rear = NULL, *ptr;

node *newnode()
{
	ptr = new node;
	cout << "Enter data:";
	cin >> ptr->data;
	ptr->next = NULL;
	return(ptr);
}



void enqueue(node *newnode)
{

	if (front == NULL)
		front = rear = ptr;
	else
	{
		rear->next = ptr;
		rear = ptr;
	}
}

void dequeue()
{
	if (front == rear)
		cout << "Queue is empty\n";
	else
	{
		ptr = front;
		front = front->next;
		cout << "Deleted node is " << ptr->data << "\n";
		delete(ptr);
	}
}

void printqueue()
{
	if (front == rear)
		cout << "Queue is empty\n";
	else
	{
		ptr = front;
		while (ptr != NULL)
		{
			cout << ptr->data << "->";
			ptr = ptr->next;
		}
	}
}


int main()
{
	char ch;
	node *ptr;

	do{
		cout << "\na.enqueue \nd.dequeue \np.print \ne.exit \n";
		cout << "enter your choice :";
		cin >> ch;

		switch (ch)
		{
		case 'a':
			ptr = newnode();
			enqueue(ptr);

			break;

		case 'd':
			dequeue();
			break;

		case 'p':
			printqueue();
			break;

		}

	} while (ch != 'e');
	return 0;
}
