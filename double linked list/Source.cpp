#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setfill;
using std::setw;
#include <string>
using namespace std;

struct school{
	int ID;
	string name;
	double DB;
	double oop;
	double ds;
	double logic;
	double sum;
	double average;
	string result;
	school *next;
};

school* creatnew(){
	school* node1 = new school();
	school* node2 = new school();
	cout << "ID: ";
	cin >> node1->ID;
	cout << "Name: ";
	cin >> node1->name;
	cout << "DB: ";
	cin >> node1->DB;
	cout << "Ds: ";
	cin >> node1->ds;
	cout << "oop: ";
	cin >> node1->oop;
	cout << "logic: ";
	cin >> node1->logic;
	node1->next = node2;
	cout << "The summary Details to student \n" << endl;
	return node1;

	cout << "ID: ";
	cin >> node2->ID;
	cout << "Name: ";
	cin >> node2->name;
	cout << "DB: ";
	cin >> node2->DB;
	cout << "Ds: ";
	cin >> node2->ds;
	cout << "oop: ";
	cin >> node2->oop;
	cout << "logic: ";
	cin >> node2->logic;
	node2->next = NULL;
	cout << "The summary Details to student \n" << endl;

	return node2;
}

school* summation(school* studentrec)
{
	studentrec->sum = studentrec->DB + studentrec->ds + studentrec->oop + studentrec->logic;
	return studentrec;
}

school* average(school* studentrec)
{
	studentrec->average = studentrec->sum / 4;
	return studentrec;
}

school* result(school* studentrec)
{
	int ave = studentrec->average;
	if (ave >= 85)
	{
		studentrec->result = "excellent";
	}
	else if (ave >= 75){
		studentrec->result = "Very good";
	}
	else if (ave >= 65){
		studentrec->result = "Good";
	}
	else if (ave >= 50){
		studentrec->result = "Accebtable";
	}
	else{
		studentrec->result = "fail";
	}

	return studentrec;
}

int main()
{
	school* m1 = creatnew();
	result((average(summation(m1))));
	cout << "the sum is " << m1->sum << "\n";
	cout << "the average is " << m1->average << "\n";
	cout << "the result is " << m1->result << "\n";

	school* m2 = creatnew();
	result((average(summation(m2))));
	cout << "the sum is " << m2->sum << "\n";
	cout << "the average is " << m2->average << "\n";
	cout << "the result is " << m2->result << "\n";

	system("pause");
	return 0;
}
