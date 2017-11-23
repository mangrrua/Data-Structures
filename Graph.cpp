#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#define INFINITY 9999
#define MAX 10
using namespace std;
void Mesafe(int dizi[MAX][MAX], int n, int baslagic, int hedef);
void yaz(int dizi[MAX][MAX], int n);

void main() {
	srand(time(NULL));
	int dizi[MAX][MAX], i, j, h, k, t;
	cout << "Dugum Sayisi : ";
	cin >> h;
	cout << endl;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < h; j++)
		{
			if (i == j)
			{
				dizi[i][j] = 0;
			}

			else
			{
				dizi[i][j] = 1 + rand() % 9;
			}
		}
	}
	cout << "------------ Yakinlik Matrisi --------------------" << endl; cout << endl;
	yaz(dizi, h);
	cout << "\nBaslangic Noktasini Giriniz : ";
	cin >> k;
	cout << "\nBitis Noktasini Giriniz : ";
	cin >> t;
	Mesafe(dizi, h, k, t);
	cout << endl;
	system("pause");
}
void Mesafe(int dizi[MAX][MAX], int n, int baslagic, int hedef)
{
	int maliyet[MAX][MAX], dizi1[MAX], mesafe[MAX];
	int dizi2[MAX], say, kmesafe, shedef, i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (dizi[i][j] == 0)
				maliyet[i][j] = INFINITY;
			else
				maliyet[i][j] = dizi[i][j];

	for (i = 0; i< n; i++)
	{
		mesafe[i] = maliyet[baslagic][i];
		dizi1[i] = baslagic;
		dizi2[i] = 0;
	}
	mesafe[baslagic] = 0;
	dizi2[baslagic] = 1;
	say = 1;
	while (say < n - 1) {
		kmesafe = INFINITY;
		for (i = 0; i < n; i++)
			if (mesafe[i] < kmesafe && !dizi2[i])
			{
				kmesafe = mesafe[i];
				shedef = i;
			}
		dizi2[shedef] = 1;
		for (i = 0; i < n; i++)
			if (!dizi2[i])
				if (kmesafe + maliyet[shedef][i] < mesafe[i])
				{
					mesafe[i] = kmesafe + maliyet[shedef][i];
					dizi1[i] = shedef;
				}
		say++;
	}
	if (hedef != baslagic)
	{
		cout << "\nMaliyet = " << mesafe[hedef];
		cout << "\nEn Kisa Yol = " << hedef;
		j = hedef;
		do
		{
			j = dizi1[j];
			cout << " <- " << j;
		} while (j != baslagic);
	}
}
void yaz(int dizi[MAX][MAX], int node)
{
	cout << "A |";
	for (int i = 0; i<node; i++)
	{
		cout << "  " << i;
	}
	cout << endl;
	cout << "--|---------------------------" << endl;
	for (int i = 0; i<node; i++)
	{
		cout << i << " |";
		for (int j = 0; j<node; j++)
		{
			if (dizi[i][j] == 0)
			{
				cout << "  -";
			}
			else
			{
				cout << "  " << dizi[i][j];
			}
		}
		cout << endl;
		cout << "  |" << endl;
	}
}