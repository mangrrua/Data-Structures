#include<iostream>
#include<time.h>
#define s 1000
#define s1 10000
#define s2 100000
using namespace std;

clock_t baslangic, son;
double duration;

void BubbleSort(int arry[], int size);
void SelectionSort(int arry[], int size);
void InsertionSort(int arry[], int size);
void QuickSort(int arry[], int left, int right);
void RandomGenerator(int arry[], int arry1[], int size);
void TestAlgorithm(int arry[], int arry1[], int size);
void tmp(int arry[], int arry1[], int size);


int main()
{

	int arry[s], arry1[s];
	int arry2[s1], arry3[s1];
	int arry4[s2], arry5[s2];
	TestAlgorithm(arry, arry1, s); cout << endl;
	TestAlgorithm(arry2, arry3, s1); cout << endl;
	TestAlgorithm(arry4, arry5, s2); cout << endl;

	system("pause");
}
void TestAlgorithm(int arry[], int arry1[], int size)
{
	RandomGenerator(arry, arry1, size);

	baslangic = clock();
	BubbleSort(arry, size);
	son = clock();
	duration = (double)(son - baslangic) / CLOCKS_PER_SEC;
	cout << " -> Bubble Sort Duration: " << duration << endl;

	tmp(arry, arry1, size);

	baslangic = clock();
	SelectionSort(arry, size);
	son = clock();
	duration = (double)(son - baslangic) / CLOCKS_PER_SEC;
	cout << " -> Selection Sort Duration: " << duration << endl;

	tmp(arry, arry1, size);

	baslangic = clock();
	InsertionSort(arry, size);
	son = clock();
	duration = (double)(son - baslangic) / CLOCKS_PER_SEC;
	cout << " -> Insertion Sort Duration: " << duration << endl;

	tmp(arry, arry1, size);

	baslangic = clock();
	QuickSort(arry, 0, size);
	son = clock();
	duration = (double)(son - baslangic) / CLOCKS_PER_SEC;
	cout << " -> Quick Sort Duration: " << duration << endl;
}
void BubbleSort(int arry[], int size)
{
	int temp;
	int i, j;

	for (i = 1; i<size; i++)
	{
		for (j = 0; j<size - i; j++)
		{
			if (arry[j] > arry[j + 1])
			{
				temp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = temp;
			}
		}
	}
}
void SelectionSort(int arry[], int size)
{
	int i, j, min, temp;
	for (i = 0; i<size - 1; i++)
	{
		min = i;
		for (j = i + 1; j<size; j++)
		{
			if (arry[j] < arry[min])
				min = j;
		}
		temp = arry[i];
		arry[i] = arry[min];
		arry[min] = temp;
	}
}
void InsertionSort(int arry[], int size)
{
	int i, tmp, j;
	for (i = 1; i < size; i++)
	{
		tmp = arry[i];
		j = i - 1;
		while (j >= 0 && arry[j] > tmp)
		{
			arry[j + 1] = arry[j];
			j = j - 1;
		}
		arry[j + 1] = tmp;
	}
}
void QuickSort(int arry[], int left, int right)
{
	int i = left, j = right - 1;
	int tmp;
	int pivot = arry[(left + right) / 2];

	while (i <= j) {
		while (arry[i] < pivot)
			i++;
		while (arry[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arry[i];
			arry[i] = arry[j];
			arry[j] = tmp;
			i++;
			j--;
		}
	};
	if (left < j)
		QuickSort(arry, left, j);
	if (i < right)
		QuickSort(arry, i, right);
}
void RandomGenerator(int arry[], int arry1[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arry[i] = 1 + rand() % 50000;
		arry1[i] = arry[i];

	}
}
void tmp(int arry[], int arry1[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arry[i] = arry1[i];
	}
}