#include <iomanip> 
#include <string> 
using std::setfill;
using std::setw;
using std::string;
using namespace std;
#include <iostream>  
using std::endl;
float getavg(float);
#include<stdio.h>
struct node
{
	int id;
	string name;
	double DB;
	node *next;
};
node* createNode()
{
	node* node1 = new node();
	cout << "\nEnter the name: ";
	cin >> node1->name;
	cout << "\nEnter the id: ";
	cin >> node1->id;
	cout << "\nEnter the DB: ";
	cin >> node1->DB;
	node1->next = NULL;
	return node1;

}
void main()
{
	node* newnode = createNode();
	cout << newnode->name;
	cout << newnode->id;
	cout << newnode->DB;
	system("pause");
}