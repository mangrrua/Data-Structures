#include<iostream>
#include"stack.h"
using namespace std;

int main()
{
	stack s;
	cout << "Enter the stack's size: ";
	cin >> s.stack_size;
	if (cin.fail())
	{
		cout << endl;
		cout << " ! You make a mistake in selection ! " << endl;
		cout << endl;
	}
	else
	{
		while (true)
		{
			char secim;
			cout << endl;
			cout << "    >>>> MENU <<<<      " << endl;cout << endl;
			cout << "> Enter stack     < E >" << endl;
			cout << "> Delete stack    < G >" << endl;
			cout << "> Stack List      < L >" << endl;
			cout << "> Stack Count     < S >" << endl;
			cout << "> Quit            < Q >" << endl;cout << endl;
			cout << ">> Enter the choice: ";
			cin >> secim;cout << endl;

			if (secim == 'E' || secim == 'e')
			{
				int item;
				cout << "> Enter the number: ";
				cin >> item;
				s.stack_Add(item);
			}
			else if (secim == 'G' || secim == 'g')
			{
				s.stack_Delete();
			}
			else if (secim == 'L' || secim == 'l')
			{
				s.stack_List();
			}
			else if (secim == 'S' || secim == 's')
			{
				s.stack_Count();
			}
			else if (secim == 'Q' || secim == 'q')
			{
				exit(0);
			}
			else
			{
				cout << " ! You make a mistake in selection ! " << endl;cout << endl;
			}
		}
	}


	

	system("pause");
}