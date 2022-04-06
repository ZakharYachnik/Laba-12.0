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

struct students
{
	char FIO[30];
	int YearB;
	int YearEn;
	int marks[4];
	struct students* next;
};

typedef struct students Node;
typedef Node* NodePtr;

int sizeL = 0;

void add(NodePtr* s)
{
	NodePtr newP, cur, prev;

	newP = (NodePtr)malloc(sizeof(Node));

	char fio[30];
	int YeB, YeEn, mark[4];

	cout <<  "\n\nВведите ФИО: ";
	gets_s(fio);
	perevod(fio);

	printf("\nВведите оценку по физике (по 5-балльной шкале): ");
	while (1) {
		mark[0] = vvod();
		if (mark[0] < 0 || mark[0] > 5)
			printf("Оценка введена некорректно, попробуйте еще раз: ");
		else break;
	}
	

	printf("\nВведите оценку по высшей математике (по 5-балльной шкале): ");
	while (1) {
		mark[1] = vvod();
		if (mark[1] < 0 || mark[1] > 5)
			printf("Оценка введена некорректно, попробуйте еще раз: ");
		else break;
	}
	

	printf("\nВведите оценку по информатике (по 5-балльной шкале): ");
	while (1) {
		mark[2] = vvod();
		if (mark[2] < 0 || mark[2] > 5)
			printf("Оценка введена некорректно, попробуйте еще раз: ");
		else break;
	}

	printf("\nВведите год рождения студента: ");
	while (1) {
		YeB = vvod();
		if (YeB < 1980)
			printf("Как-то староват для студента:), попробуйте еще раз: ");
		else if (YeB > 2022)
			printf("Пусть для начала родится:), попробуйте еще раз");
		else break;
	}


	printf("\nВведите год поступления студента в БГУИР: ");
	while (1) {
		YeEn = vvod();
		if (YeEn < 2015)
			printf("Он уже выпустился:), попробуйте еще раз: ");
		else if (YeEn < YeB && YeEn < 2023)
			printf("Он тогда еще не родился:), попробуйте еще раз: ");
		else if (YeEn > 2022)
			printf("Мы живем в 2022:), попробуйте еще раз: ");
		else break;
	}



	strcpy_s(newP->FIO, 30, fio);
	newP->marks[0] = mark[0];
	newP->marks[1] = mark[1];
	newP->marks[2] = mark[2];
	newP->YearB = YeB;
	newP->YearEn = YeEn;
	newP->next = NULL;
	prev = NULL;
	cur = *s;


	while (cur != NULL)
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

void Del(NodePtr* s)
{
	if (*s == NULL) {
		cout << "\nThe list is empty";
		return;
	}

	cout << endl << "\nВведите какую запись хотите удалить: ";
	int ch = vvod();

	while (ch < 1 || ch > sizeL)
	{
		cout << "\nТакой записи не существует, попробуйте еще раз ";
		ch = vvod();
	}

	NodePtr prev = NULL, cur = *s, temp;


	if (ch == 1)
	{
		temp = *s;
		*s = (*s)->next;
		cur = *s;
		free(temp);
		sizeL--;
		return;
	}


	int i = 1;
	while (i != ch)
	{
		prev = cur;
		cur = cur->next;
		i++;
	}

	temp = cur;
	prev->next = cur->next;
	cur = cur->next;
	free(temp);

	cout << "\nЗапись успешно удалена!!!\n";
	sizeL--;
}

void  ListPrint(NodePtr cur)
{
	int i = 1;
	if (cur == NULL)
		cout << "\nError! The List is empty(\n";
	else{
		printf("\n ------------------------------------------------------------------------------------------\n");
		printf(" %c#%c  ФИО студента  %c  Год рождения  %c Год поступления %c  Физика  %c Выш мат %c Информатика %c\n", 166, 166, 166,166,166,166,166,166);
		printf(" ------------------------------------------------------------------------------------------\n");
		
		while (cur != NULL)
		{
			printf("\n ------------------------------------------------------------------------------------------\n");
			printf(" %c%d%c%14s%13d%17d%14d%11d%11d      %c\n",166, i , 166, cur->FIO, cur->YearB, cur->YearEn, cur->marks[0], cur->marks[1], cur->marks[2], 166);
			printf(" ------------------------------------------------------------------------------------------\n");

			cur = cur->next;

			if(cur != NULL)
			printf("\n    %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c   %c\n", 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25);
			i++;
		}
		}
}

int menu()
{
	int ch = 0;
	while (ch < 1 || ch > 4) {
		printf("\n\nВыберете действие\n\n");
		printf("----------------------------------------");
		printf("\n| 1. Добавить элемент списка           |\n");
		printf("----------------------------------------");
		printf("\n| 2. Вывести список                    |\n");
		printf("----------------------------------------");
		printf("\n| 3. Удалить элемент списка            |\n");
		printf("----------------------------------------");
		printf("\n| 4. Выход                             |\n");
		printf("----------------------------------------");

		printf("\n\nВаш выбор: ");
		ch = vvod();
		printf("\n");
	}
	return ch;
}

int main()
{
	setlocale (LC_ALL, "Rus");

	NodePtr start = NULL;

	while (1) {
		switch (menu())
		{
			case 1:
				add(&start);
				break;

			case 2:
				ListPrint(start);
				break;

			case 3:
				Del(&start);
				break;

			case 4:
				return 0;
		}
	}
}
