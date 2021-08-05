#include <iostream>
#define MAX_SIZE 10
using namespace std;


void merge_sort(int, int);
void merge_array(int, int, int, int);
int arr_sort[MAX_SIZE];


int main()
{
	cout << "\nEnter " << MAX_SIZE << " Elements for Sorting : " << endl;
	for (int i = 0; i < MAX_SIZE; i++)
		cin >> arr_sort[i];

	cout << "\nYour Data   :";
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << "\t" << arr_sort[i];
	}

	merge_sort(0, MAX_SIZE - 1);

	cout << "\n\nSorted Data :";
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << "\t" << arr_sort[i];
	}

}



void merge_sort(int i, int j) {
	int m;

	if (i < j) {        //0<max=10
		m = (i + j) / 2;
		merge_sort(i, m);
		merge_sort(m + 1, j);       //for loop
		// Merging two arrays
		merge_array(i, m, m + 1, j);
	}
}

//merge array
void merge_array(int a, int b, int c, int d)
{
	int t[50];      //array name t contain 50 elements

	int i = a, j = c, k = 0;

	while (i <= b && j <= d)
	{
		if (arr_sort[i] < arr_sort[j])
			t[k++] = arr_sort[i++];
		else
			t[k++] = arr_sort[j++];
	}

	//collect remaining elements
	while (i <= b)
		t[k++] = arr_sort[i++];

	while (j <= d)
		t[k++] = arr_sort[j++];

	for (i = a, j = 0; i <= d; i++, j++)
		arr_sort[i] = t[j];
}
