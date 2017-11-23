#include<iostream>
using namespace std;

void list_ekle(int);
void list_listele();
int list_say();
void list_sil(int);
void list_ters_listele();



typedef struct list_element {
	int value;
	struct list_element *ilk;
	struct list_element *son;

}Element;

Element *list_arama(int ara);

Element *head = NULL;
Element *last = NULL;

int main()
{
	while (true)
	{
		cout << endl;
		cout << "--------- MENU ---------" << endl;
		cout << endl;
		cout << "> Ekle           [E]" << endl;
		cout << "> Sil            [S]" << endl;
		cout << "> Listele        [L]" << endl;
		cout << "> Listele(Ters)  [T]" << endl;
		cout << "> Eleman sayisi  [P]" << endl;
		cout << "> Cikis          [Q]" << endl;
		cout << endl;
		cout << "-------------------------" << endl;
		char secim;
		cout << endl;
		cout << "Seciminizi yapiniz: ";
		cin >> secim;
		cout << endl;

		if (secim == 'E' || secim == 'e')
		{
			int ekle;
			cout << "> Eklemek istediginiz sayiyi giriniz: ";
			cin >> ekle;
			list_ekle(ekle);

		}
		else if (secim == 'S' || secim == 's')
		{
			int sil;
			cout << "> Silmek istediginiz elemani seciniz: ";
			cin >> sil;
			list_sil(sil);

		}
		else if (secim == 'L' || secim == 'l')
		{
			list_listele();
			
		}
		else if (secim == 'P' || secim == 'p')
		{
			list_say();
		}
		else if (secim == 'Q' || secim == 'q')
		{
			exit(0);
		}
		else if (secim == 'T' || secim == 't')
		{
			list_ters_listele();
		}
		else
		{
			cout << "HATALI SECIM YAPTINIZ !" << endl;
		}

	}


	system("pause");
}
void list_ekle(int deger)
{
	list_element *deneme = new list_element;
	if (last != NULL)
	{
		last->son = deneme;
		deneme->ilk = last;
		deneme->value = deger;
		last = deneme;
		last->son = NULL;
	}
	else
	{
		head = deneme;
		last = deneme;
		deneme->value = deger;
		head->ilk = NULL;
		head->son = NULL;
	}
}
void list_listele()
{
	int i = 1;
	Element *listele;
	listele = head;
	if (listele == NULL)
	{
		cout << "Liste Boþ" << endl;
	}
	cout << "----- Liste Normal Siralama ----" << endl;
	cout << endl;
	while (listele)
	{
		cout << i << " > " << listele->value << endl;
		listele = listele->son;
		i++;
	}
	cout << endl;
	cout << "--------------------------------" << endl;
}
int list_say()
{
	int i = 0;
	Element *listele;
	listele = head;
	if (listele == NULL)
	{
		cout << "Liste Boþ" << endl;
	}
	while (listele)
	{
		i++;
		listele = listele->son;
	}
	cout << "Listenin eleman sayisi: " << i << endl;
	return i;
}
void list_sil(int sil)
{
	Element *p;
	p = list_arama(sil);

	if (p != NULL)
	{
		if (head == p)
		{
			if (head->son == NULL)
			{
				head = NULL;
				last = NULL;
			}
			else
			{
				head = p->son;
				head->ilk = NULL;
			}
		}
		else
		{
			if (p == last)
			{
				last = last->ilk;
				last->son = NULL;
			}
			else
			{
				p->ilk->son = p->son;
				p->son->ilk = p->ilk;
			}
		}
		free(p);
	}
	else
	{
		cout << "Liste Bos." << endl;
		cout << endl;
	}
}
void list_ters_listele()
{
	int i = 1;
	Element *listele;
	listele = last;
	if (listele == NULL)
	{
		cout << "Liste Boþ" << endl;
	}
	cout << endl;
	cout << "----- Liste Tersten Siralama ---" << endl;
	cout << endl;
	while (listele)
	{
		cout << i << " > " << listele->value << endl;
		listele = listele->ilk;
		i++;
	}
	cout << endl;
	cout << "--------------------------------" << endl;
}
Element *list_arama(int ara)
{

	Element *p;

	p = head;

	while (p != NULL) {

		if (p->value == ara)

			return p;

		p = p->son;

	}
	cout << "Aradiginiz eleman bulunamadý." << endl;
	return NULL; 

}