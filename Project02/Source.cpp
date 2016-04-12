#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

void generateData(vector<int> &list);
void print(vector<int> &list);
void quickSwap(vector<int> &list, int x, int y);
void quickSort(vector<int>& list, int left, int right);
int partition(vector<int> &list, int first, int last);
int median(vector<int> &list, int first, int last);

// Global sort type value
int sortType = 0;

int main()
{
	int menuChoice = 0;

	while (menuChoice != 9)
	{
		cout << "Choose a sorting method:" << endl;
		cout << "1. Sort array using pivot as middle element of array." << endl;
		cout << "2. Sort array using pivot as median element of array." << endl;
		cout << "3. Sort array using pivot as the middle element but insertion for lists less than 20." << endl;
		cout << "4. Sort array using pivot as median element but insertion for lists less than 20." << endl;
		cout << "9. Exit Program." << endl << endl;
		cout << "Enter your selection: ";
		cin >> menuChoice;

		vector<int> list(10000);
		generateData(list);
		clock_t x;
		clock_t y;

		switch (menuChoice)
		{
		case 9:
			break;
		case 1:
			sortType = 1;
			x = clock();
			quickSort(list, 0, 9999);
			y = clock();
			cout << "Total CPU Time for Sort Method 1: " << y - x << endl << endl;
			break;
		case 2:
			sortType = 2;
			x = clock();
			quickSort(list, 0, 9999);
			y = clock();
			cout << "Total CPU Time for Sort Method 2: " << y - x << endl << endl;
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
		}

	}

	system("Pause");
	return 0;
}

void generateData(vector<int> &list)
{
	srand(time(NULL));
	for (auto &i : list)
	{
		i = rand() % 99;
	}
}

void print(vector<int> &list)
{
	cout << endl;
	for (auto &i : list)
	{
		cout << i << " ";
	}
	cout << endl;
}

void quickSwap(vector<int> &list, int x, int y)
{
	int temp = list[x];
	list[x] = list[y];
	list[y] = temp;
}

void quickSort(vector<int> &list, int first, int end)
{
	int location;
	if (first < end)
	{
		location = partition(list, first, end);
		quickSort(list, first, location - 1);
		quickSort(list, location + 1, end);
	}
}

int partition(vector<int> &list, int first, int last)
{
	int pivot;
	int index, smallIndex;

	if (sortType == 1) //sort with middle
		quickSwap(list, first, (first + last) / 2);
	if (sortType == 2) //sort with median
		quickSwap(list, first, median(list, first, last)); 
	
	pivot = list[first];
	smallIndex = first;

	for (index = first + 1; index <= last; index++)
	{
		if (list[index] < pivot)
		{
			smallIndex++;
			quickSwap(list, smallIndex, index);
		}
	}
	quickSwap(list, first, smallIndex);

	return smallIndex;
}

int median(vector<int>& list, int first, int last)
{
	if (list[first] < list[last])
	{
		if (list[(first + last) / 2] < list[first])
			return first;
		else if (list[last] < list[(first + last) / 2])
			return last;
		else
			return (first + last) / 2;
	}
	else if (list[(first + last) / 2] < list[last])
		return last;
	else if (first < list[(first + last) / 2])
		return first;
	else
		return (first + last) / 2;
}
