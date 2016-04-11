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


int main()
{
	vector<int> list(10);
	generateData(list);
	print(list);
	quickSort(list, 0, 9);
	print(list);

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

	quickSwap(list, first, median(list, first, last)); // sort with median
	//quickSwap(list, first, (first + last) / 2); // sort with middle
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
