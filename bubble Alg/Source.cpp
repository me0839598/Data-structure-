#include <iostream>

using namespace std;

int main()
{
	int arr[6] = { 10, 5, 3, 2, 9, 1 };
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<5; j++) //because 5 compare
		{
			if (arr[j]>arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

	}
	for (int i = 0; i<6; i++)
	{
		cout << arr[i] << "  ";
	}
	return 0;
}
