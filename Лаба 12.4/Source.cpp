#include <iostream>
#include <stdio.h>
#include<locale.h>
#include<string.h>
#include <stdlib.h>
#include<Windows.h>

using namespace std;

int vvod()
{
	int ch;

	while (1)
	{
		if (scanf_s("%d", &ch) != 1) {
			getchar();
			printf("\nВведен неверный тип, попробуйте еще раз ");
		}
		else break;

	}
	getchar();
	return ch;
}

void perevod(char a[30])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] >= -96 && a[i] <= -81)//для маленьких букв
			a[i] += 64;
		else
			if (a[i] >= -32 && a[i] <= -17)
				a[i] += 16;
			else if (a[i] >= -128 && a[i] <= -97) // для больших букв
				a[i] += 64;

	}
}

struct simbols
{
	char simb;
	struct simbols* next;
};

typedef struct simbols Node;
Node* Top = NULL;

int sizeL = 0;

void add(int max)
{
	Node* newP;

	newP = (Node*)malloc(sizeof(Node));

	char sim, Etal;
	
	cout << "\nВведите эталонный символ: ";
	cin >> Etal;

	cout << "\nВводите символы до встречи эталонного или до полного заполнения стека:\n";
	cin >> sim;

	if (sim == Etal)
	{
		cout << "\nПервым введен эталонный символ, стек остается пустым!";
		return;
	}
	newP->simb = sim;
	newP->next = NULL;
	Top = newP;
	sizeL++;

	cin >> sim;
	while (sim != Etal && sizeL < max)
	{
		newP = (Node*)malloc(sizeof(Node));
		newP->simb = sim;
		newP->next = Top;
		Top = newP;
		sizeL++;
		cin >> sim;
	}

	if (sizeL == max)
	{
		cout << "\nВвод приостановлен из-за переполнения стека!";
	}
	else
	{
		cout << "\nВвод приостановлен из-за встречи эталонного символа!";
	}
	
}


void stackPrint()
{
	if (sizeL == 0)
	{
		cout << "\nThe stack is empty!!!\n";
		return;
	}


	Node* cur = Top;

	cout << "Введенный стек:\n\n";

	while (cur != NULL)
	{
		cout <<"   " << cur->simb ;

		cur = cur->next;

		if (cur != NULL)
			printf("\n   %c\n", 25);

		
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	int max;

	cout << "\nВведите максимальный размер стека: ";
	max = vvod();

	add(max);

	cout << endl << endl;

	stackPrint();
	cout << endl << endl;
}