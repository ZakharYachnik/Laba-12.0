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

struct List
{
	int num;
	struct List* next;
};

typedef struct List Node;
typedef Node* NodePtr;

int sizeL = 0;

void add(NodePtr* s, int val)
{
	NodePtr newP, cur, prev;

	newP = (NodePtr)malloc(sizeof(Node));

	newP->num = val;
	newP->next = NULL;
	prev = NULL;
	cur = *s;


	while (cur != NULL && val > cur->num)
	{
		prev = cur;
		cur = cur->next;
	}


	if (prev == NULL)
	{
		newP->next = *s;
		*s = newP;
	}
	else
	{
		prev->next = newP;
		newP->next = cur;
	}

	sizeL++;
}

int menu()
{
	int ch = 0;
	while (ch < 1 || ch > 9) {
		printf("\n\nВыберете действие\n\n");
		printf("----------------------------------------");
		printf("\n| 1. Добавить элемент списка           |\n");
		printf("----------------------------------------");
		printf("\n| 2. Вывести список                    |\n");
		printf("----------------------------------------");
		printf("\n| 3. Найти максимальный элемент списка |\n");
		printf("----------------------------------------");
		printf("\n| 4. Найти минимальный элемент списка  |\n");
		printf("----------------------------------------");
		printf("\n| 5. Удалить все повторения числа      |\n");
		printf("----------------------------------------");
		printf("\n| 6. Удалить все вхождения числа       |\n");
		printf("----------------------------------------");
		printf("\n| 7. Ввести элемент до определенного   |\n");
		printf("----------------------------------------");
		printf("\n| 8. Ввести после определенного        |\n");
		printf("----------------------------------------");
		printf("\n| 9. Выход                             |\n");
		printf("----------------------------------------");

		printf("\n\nВаш выбор: ");
		ch = vvod();
		printf("\n");
	}
	return ch;
}

void  ListPrint(NodePtr cur)
{
	int i = 1;
	if (cur == NULL)
		cout << "\nError! The List is empty(\n";
	else
		while (cur != NULL)
		{
			cout << "   " << cur->num;

			cur = cur->next;

			if (cur != NULL)
				printf("\n   %c\n", 25);
		}
}

void FindMax(NodePtr cur)
{

	if (cur == NULL) {
		cout << "\nThe list is empty";

	}
	else {
		int max = cur->num;
		while (cur != NULL)
		{
			if (max < cur->num)
				max = cur->num;
			cur = cur->next;
		}

		cout << "\nMAX = " << max;
	}
}

void FindMin(NodePtr cur)
{

	if (cur == NULL) {
		cout << "\nThe list is empty";
	}
	else {
		int min = cur->num;
		while (cur != NULL)
		{
			if (min > cur->num)
				min = cur->num;
			cur = cur->next;
		}

		cout << "\nMIN = " << min;
	}
}


void delNum(NodePtr* s, int number)
{
	if (*s == NULL) {
		cout << "\nThe list is empty";
		return;
	}

	NodePtr prev = NULL, cur = *s, temp;

	while (cur != NULL)
	{
		if (number == cur->num)
		{
			if (prev == NULL)
			{
				temp = *s;
				*s = (*s)->next;
				cur = *s;
				free(temp);
			}
			else
			{
				temp = cur;
				prev->next = cur->next;
				cur = cur->next;
				free(temp);
			}
			sizeL--;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void delRep(NodePtr* s, int number)
{
	if (*s == NULL) {
		cout << "\nThe list is empty";
		return;
	}

	NodePtr prev = NULL, cur = *s, temp;

	int i = 0;

	while (cur != NULL)
	{
		if (number == cur->num)
		{
			if (i != 0)
			{
				temp = cur;
				prev->next = cur->next;
				cur = cur->next;
				free(temp);
				sizeL--;
			}
			else
			{
				i++;
				prev = cur;
				cur = cur->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void insAft(NodePtr* s, int value)
{
	if (*s == NULL) {
		cout << "\nThe list is empty";
		return;
	}

	cout << "\nВведите после какого хотите ввести число: ";
	int a;

	while (1)
	{
		a = vvod();
		if (a > sizeL || a < 1)
		{
			cout << "\nНе подходит, попробуйте еще раз: ";
		}
		else break;
	}

	NodePtr newP, cur;

	newP = (NodePtr)malloc(sizeof(Node));

	newP->num = value;
	newP->next = NULL;
	cur = *s;

	for (int i = 1; i < a; i++)
	{
		cur = cur->next;
	}

	newP->next = cur->next;
	cur->next = newP;
	sizeL++;
}

void insBef(NodePtr* s, int value)
{
	if (*s == NULL) {
		cout << "\nThe list is empty";
		return;
	}

	cout << "\nВведите до какого хотите ввести число: ";
	int a;

	while (1)
	{
		a = vvod();
		if (a > sizeL || a < 1)
		{
			cout << "\nНе подходит, попробуйте еще раз: ";
		}
		else break;
	}

	NodePtr newP, cur;

	newP = (NodePtr)malloc(sizeof(Node));

	newP->num = value;
	newP->next = NULL;
	cur = *s;

	if (a == 1)
	{
		(*s) = newP;
		(*s)->next = cur;
		sizeL++;
		return;
	}

	for (int i = 1; i < a - 1; i++)
	{
		cur = cur->next;
	}

	newP->next = cur->next;
	cur->next = newP;

	sizeL++;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	NodePtr start = NULL;
	int elem;

	while (1) {
		switch (menu())
		{
		case 1:
			cout << "Введите какое число хотите добавить: ";
			elem = vvod();
			add(&start, elem);
			cout << "\nУспешно добавленно\n";
			break;

		case 2:
			ListPrint(start);
			break;

		case 3:
			FindMax(start);
			break;

		case 4:
			FindMin(start);
			break;

		case 5:
			cout << "\nВведите повторения какого числа хотите удалить: ";
			elem = vvod();
			delRep(&start, elem);
			break;

		case 6:
			cout << "\nВведите какое число хотите удалить хотите удалить: ";
			elem = vvod();
			delNum(&start, elem);
			break;

		case 7:
			cout << "\nВведите число которое хотите добавить: ";
			elem = vvod();
			insBef(&start, elem);
			break;

		case 8:
			cout << "\nВведите число которое хотите добавить: ";
			elem = vvod();
			insAft(&start, elem);
			break;

		case 9:
			return 0;
		}
	}
}
