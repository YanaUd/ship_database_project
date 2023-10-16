#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <malloc.h>
#include "H.h"

int checkstr(char* str) ///�������� ������������ ��������� ������
{

	///������� isspace(ch) ���������� ��������� ��������, ���� �������� ch �������� ���������� ��������, � ��������� ������ ������������ ����

	///������� isalpha(ch) ���������� ��������� ��������, ���� �� �������� ch �������� ������, � ��������� ������ ������������ ����

	for (int i = 0; i < strlen(str); i++)
		if ((isspace(str[i]) == 0) && (isalpha(str[i]) == 0) && (str[i] != '.'))
		{
			return 1;
		}

	return 0;

}

int fill(char* name) ///���������� ���� ������

{

	FILE* f;

	Ship ship;

	int n;
	int p;
	int k;
	char clear;

	printf("\n������� ���������� ��������: ");

	while ((scanf("%d", &n) == 0) || (n <= 0))

	{

		printf("������������ ����\n");

		printf("\n������� ���������� ��������: ");

	}

	if ((f = fopen(name, "wb")) == NULL) ///��������, ��� ���� ������� ������

	{

		printf("error1\n");

		return(-1);

	}

	for (int i = 0; i < n; i++) ///���� ������

	{
		p = 0;
		rewind(stdin);

		printf("\n������� ������ %d-��� �������:\n", i + 1);

		printf("��� ��������: ");

		gets(ship.name);

		while (checkstr(ship.name))

		{

			printf("������ �������� ������������ �������\n");

			printf("��� ��������: ");

			gets(ship.name);

		}

		printf("�������� �����: ");

		gets(ship.sudno);

		while (checkstr(ship.sudno))

		{

			printf("������ �������� ������������ �������\n");

			printf("��� ��������: ");

			gets(ship.sudno);

		}

		printf("������: ");

		gets(ship.country);

		while (checkstr(ship.country))

		{

			printf("������ �������� ������������ �������\n");

			printf("������ ���������: ");

			gets(ship.country);

		}


		printf("�������������� ����������� 1.�� 2.���\n");
		scanf("%d", &p);

		while ((p <= 0) || (p > 2)) {
			printf("\n������������ ����\n�������� �������������� ������������:\n");
			scanf("%d", &p);
		}

		switch (p) {
		case 1:
			strcpy(ship.shipping, "Yes");
			break;
		case 2:
			strcpy(ship.shipping, "No");
			break;
		}
		//getchar();
		printf("������� ��� ������� 1.������ 2.�������� 3.������������\n");
		scanf("%d", &k);

		while ((k <= 0) || (k > 3)) {
			printf("\n������������ ����\n�������� ��� �������:\n");
			scanf("%d", &k);
		}

		switch (k) {
		case 1:
			strcpy(ship.type, "Tanker");
			break;
		case 2:
			strcpy(ship.type, "Suhogruz");
			break;
		case 3:
			strcpy(ship.type, "Passazhirskiy");
			break;
		}
		
		printf("��� ���������: ");

		scanf("%d", &(ship.year));

		while (ship.year < 0)

		{

			printf("������������ ����\n");

			printf("��� ���������: ");

			scanf("%d", &(ship.year));

		}
		printf("����� ���������: ");

		scanf("%d", &(ship.summa));

		

		while (ship.summa < 0)

		{

			printf("������������ ����\n");

			printf("����� ���������: ");

			scanf("%d", &(ship.summa));

		}

		printf("�������������: ");

		scanf("%d", &(ship.water));

		

		while (ship.water < 0)

		{

			printf("������������ ����\n");

			printf("�������������: ");

			scanf("%d", &(ship.water));

		}


		fwrite(&ship, sizeof(ship), 1, f); ///���������� ������ ������� � ����

	}

	printf("\n���� ������ � ��������� ������� ���������\n\n");

	fclose(f);

	return 0;

}

int add(char* name){///���������� ������ � ����
	int p,k;
	FILE* f;

	Ship ship;

	if ((f = fopen(name, "ab")) == NULL) ///��������� ���� ��� �� ������

	{

		printf("error1\n");

		return(-1);

	}


	printf("������� ������ �������:\n");

	printf("��� ��������: ");

	getchar();

	gets(ship.name);

	while (checkstr(ship.name))

	{

		printf("������ �������� ������������ �������\n");

		printf("��� ��������: ");

		gets(ship.name);

	}


	printf("�������� �����: ");

	gets(ship.sudno);

	while (checkstr(ship.sudno))

	{

		printf("������ �������� ������������ �������\n");

		printf("��� ��������: ");

		gets(ship.sudno);

	}

	fflush(stdin);

	printf("������: ");

	gets(ship.country);

	while (checkstr(ship.country))

	{

		printf("������ �������� ������������ �������\n");

		printf("������ ���������: ");

		gets(ship.country);

	}

	printf("��� ���������: ");

	scanf("%d", &(ship.year));

	

	while (ship.year < 0)

	{

		printf("������������ ����\n");

		printf("��� ���������: ");

		scanf("%d", &(ship.year));

	}

	printf("�������������: ");
	scanf("%d", &(ship.water));


	while (ship.water < 0)
	{
		printf("������������ ����\n");

		printf("�������������: ");

		scanf("%d", &(ship.water));

	}

	printf("����� ���������: ");

	scanf("%d", &(ship.summa));


	while (ship.summa < 0)

	{

		printf("������������ ����\n");

		printf("����� ���������: ");

		scanf("%d", &(ship.summa));

	}


	printf("�������������� ����������� 1.�� 2.���\n");
	scanf("%d", &p);

	while ((p <= 0) || (p > 2)) {
		printf("\n������������ ����\n�������� �������������� ������������:\n");
		scanf("%d", &p);
	}

	switch (p) {
	case 1:
		strcpy(ship.shipping, "Yes");
		break;
	case 2:
		strcpy(ship.shipping, "No");
		break;
	}
	//getchar();

	printf("������� ��� ������� 1.������ 2.�������� 3.������������\n");

	scanf("%d", &k);

	while ((k <= 0) || (k > 3)) {
		printf("\n������������ ����\n�������� ��� �������:\n");
		scanf("%d", &k);
	}

	switch (k) {
	case 1:
		strcpy(ship.type, "Tanker");
		break;
	case 2:
		strcpy(ship.type, "Suhogruz");
		break;
	case 3:
		strcpy(ship.type, "Passazhirskiy");
		break;
	}

	fwrite(&ship, sizeof(Ship), 1, f);

	printf("\n������ ���������\n\n");

	fclose(f);

	return 0;

}

int delete_f(char* name) ///�������� �������� ������ �� ����

{

	FILE* f;

	Ship ship;

	if ((f = fopen(name, "r+b")) == NULL) ///������ � ������

	{

		printf("error1\n");

		return(-1);

	}

	int num, last, if_show;

	printf("����� ���������� ������ ������ ������� 1\n"

		"����� ���������� ��� ������ ������� 0\n");

	scanf("%d", &if_show);

	while ((if_show != 1) && (if_show != 0)) ///������������ ����
	{
		printf("����� ���������� ������ ������ ������� 1\n"

			"����� ���������� ��� ������ ������� 0\n");

		scanf("%d", &if_show);
	}
	if (if_show) show(name);

	printf("������� ����� �������, ����� ������� ������ �� ����: ");

	while ((scanf("%d", &num) == 0) || (num <= 0))

	{
		printf("������������ ����\n");

		printf("������� ����� �������, ����� ������� ������ �� ����: ");
	}

	fseek(f, 0, SEEK_END); /// ������� ���-�� ������� � ����

	last = ftell(f) / sizeof(Ship);

	if (num > last) /// ��������, ���� �� � ���� ������ � ������ �������

	{

		printf("� ���� ��� ������� � ������� %d, ������� ��� ���:\n", num);

		while ((scanf("%d", &num) == 0) || (num <= 0) || (num > last))

		{

			printf("������������ ����\n");

			printf("������� ����� �������, ����� ������� ������ �� ����: ");

		}

	}

	for (int i = num - 1; i < last - 1; i++) ///���������� ������ ����� ���������, ������� ���� �������
	{
		fseek(f, (i + 1) * sizeof(Ship), SEEK_SET);

		fread(&ship, sizeof(Ship), 1, f); ///��������� ��������� �������

		fseek(f, i * sizeof(Ship), SEEK_SET); ///������������ �����

		fwrite(&ship, sizeof(Ship), 1, f); ///���������� ��������� ������� ������ ��������

	}

	if (_chsize(_fileno(f), (last - 1) * sizeof(Ship)) == 0) /// ��������� ������ �����

		printf("������ �������\n\n");

	else printf("������ ���������� �������\n");

	fclose(f);

	return 0;

}

int search(char* name) ///����� ������ �� ��������� ����

{

	FILE* f;

	Ship ship;

	int p, i, flag, mark, k;

	char str[20];

	if ((f = fopen(name, "rb")) == NULL)

	{

		printf("error1\n");

		return(-1);

	}

	printf("\n�������� ���� ��� ������:\n");

	printf("1. ��� ��������\n");

	printf("2. ������\n");

	printf("3. ��� ���������\n");

	printf("4. ����� ���������\n");

	printf("5. �������� �����\n");

	printf("6. �������������\n");

	printf("7. ��� �������\n");

	printf("8. �����������\n");


	printf("> ");

	while ((scanf("%d", &p) == 0) || (p <= 0) || (p > 8))

	{

		printf("\n������������ ����\n"

			"�������� ���� ��� ������:\n"

			">");

	}

	switch (p)

	{

	case 1:

	{

		i = 1;

		flag = 0; ///���������� ��� ������� ����������

		printf("������� ��� ��������: ");

		rewind(stdin);

		gets(str);

		printf(" ___________________________________________________________________________________________________________________________________ \n");


		printf("| � |    �������     |     ������    |     ���    | ��������� |          �����       | �������������  | ��� �������   |  �����������|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///���� �� ����� �����

		{

			fread(&ship, sizeof(Ship), 1, f); ///��������� ������ ����� ������

			if (!feof(f) && !strcmp(ship.name, str)) ///���� ������� ����������

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///���� ���������� ���

		{

			printf("| |\n"

				"| ���������� ��� |\n"

				"|____________________________________________________________________________________________________________________________________________|\n");
			
			break;

		}

		printf("\n");

		break;

	}

	case 2:

	{

		i = 1;

		flag = 0;

		printf("������� ������: ");

		rewind(stdin);

		gets(str);

		printf(" ___________________________________________________________________________________________________________________________________\n");

		printf("| | | | | | | | | |\n");

		printf("| � |    �������     |     ������    |     ���    | ��������� |          �����       | �������������  | ��� �������   |  �����������|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///���� �� ����� �����

		{

			fread(&ship, sizeof(Ship), 1, f); ///��������� ������ ����� ������

			if (!feof(f) && !strcmp(ship.country, str)) ///���� ������� ����������

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///���� ���������� ���

		{

			printf("| |\n"

				"| ���������� ��� |\n"

				"|____________________________________________________________________________________________________________________________________________|\n");

			break;

		}

		printf("\n");

		break;

	}

	case 3:

	{

		i = 1;

		flag = 0;

		printf("������� ��� ��������� : ");

		int year = 0;

		scanf("%d", &year);

		while (year < 0)

		{

			printf("������������ ����\n");

			printf("������� ��� ���������: ");

			scanf("%d", &year);

		}

		printf(" ___________________________________________________________________________________________________________________________________\n");

		printf("| | | | | | | | | |\n");

		printf("| � |    �������     |     ������    |     ���    | ��������� |          �����       | �������������  | ��� �������   |  �����������|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///���� �� ����� �����

		{

			fread(&ship, sizeof(Ship), 1, f); ///��������� ������ �� ����� ������

			if (!feof(f) && (ship.year == year)) ///���� ������� ����������

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///���� ���������� ���

		{

			printf("| |\n"

				"| ���������� ��� |\n"

				"|_____________________________________________________________________________________________________________________________________________|\n");

			break;

		}

		printf("\n");

		break;

	}

	case 4:

	{

		i = 1;

		flag = 0;

		printf("������� ����� ���������  : ");

		int summ = 0;

		scanf("%d", &summ);

		while (summ < 0)

		{

			printf("������������ ����\n");

			printf("������� ����� ���������: ");

			scanf("%d", &summ);

		}

		printf(" ___________________________________________________________________________________________________________________________________\n");

		printf("| | | | | | | | | |\n");

		printf("| � |    �������     |     ������    |     ���    | ��������� |          �����       | �������������  | ��� �������   |  �����������|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");
		while (!feof(f)) ///���� �� ����� �����

		{

			fread(&ship, sizeof(Ship), 1, f); ///��������� ������ �� ����� ������

			if (!feof(f) && (ship.summa == summ)) ///���� ������� ����������

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///���� ���������� ���

		{

			printf("| |\n"

				"| ���������� ��� |\n"

				"|____________________________________________________________________________________________________________________________________________|\n");

			break;

		}

		printf("\n");

		break;

	}

	case 5:
	{
		i = 1;

		flag = 0; ///���������� ��� ������� ����������

		printf("������� �������� �����: ");

		rewind(stdin);

		gets(str);

		printf(" ___________________________________________________________________________________________________________________________________ \n");

		printf("| | | | | |\n");

		printf("| � |    �������     |     ������    |     ���    | ��������� |          �����       | �������������  | ��� �������   |  �����������|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///���� �� ����� �����

		{

			fread(&ship, sizeof(Ship), 1, f); ///��������� ������ ����� ������

			if (!feof(f) && !strcmp(ship.sudno, str)) ///���� ������� ����������

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///���� ���������� ���

		{

			printf("| |\n"

				"| ���������� ��� |\n"

				"|_______________________________________________________________________________________________________________________________________________|\n");

			break;

		}

		break;

	}

	


	case 6:

	{

		i = 1;

		flag = 0;

		printf("������� ������������� : ");

		int waterp = 0;

		scanf("%d", &waterp);

		while (waterp < 0)

		{

			printf("������������ ����\n");

			printf("������� ����� ���������: ");

			scanf("%d", &waterp);

		}

		printf(" ____________________________________________________________________________________________________________________________________\n");

		printf("| | | | | | | | | |\n");

		printf("| � |    �������     |     ������    |     ���    | ��������� |          �����       | �������������  | ��� �������   |  �����������|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");
		while (!feof(f)) ///���� �� ����� �����

		{

			fread(&ship, sizeof(Ship), 1, f); ///��������� ������ �� ����� ������

			if (!feof(f) && (ship.water == waterp)) ///���� ������� ����������

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///���� ���������� ���

		{

			printf("| |\n"

				"| ���������� ��� |\n"

				"|____________________________________________________________________________________________________________________________________________|\n");

			break;

		}
		break;
	}


	case 7:
	{
		i = 1;
		

		flag = 0; ///���������� ��� ������� ����������

		printf("������� ��� �����: ");

		rewind(stdin);

		gets(str);

		printf(" ____________________________________________________________________________________________________________________________________ \n");

		printf("| | | | | |\n");

		printf("| � |    �������     |     ������    |     ���    | ��������� |          �����       | �������������  | ��� �������   |  �����������|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///���� �� ����� �����

		{

			fread(&ship, sizeof(Ship), 1, f); ///��������� ������ ����� ������

			if (!feof(f) && !strcmp(ship.type, str)) ///���� ������� ����������

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///���� ���������� ���

		{

			printf("| |\n"

				"| ���������� ��� |\n"

				"|______________________________________________________________________________________________________________________________________________|\n");

			break;

		}

		printf("\n");

		break;
	}

	case 8:
	{i = 1;

	flag = 0; ///���������� ��� ������� ����������
	
	printf("������� �������������� � �����������: ");

	rewind(stdin);

	gets(str);

	printf(" ___________________________________________________________________________________________________________________________________ \n");

	printf("| | | | | |\n");

	printf("| � |    �������     |     ������    |     ���    | ��������� |          �����       | �������������  | ��� �������   |  �����������|\n");

	printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

	while (!feof(f)) ///���� �� ����� �����

	{

		fread(&ship, sizeof(Ship), 1, f); ///��������� ������ ����� ������

		if (!feof(f) && !strcmp(ship.shipping, str)) ///���� ������� ����������

		{

			printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

			i++;

			printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

		}

	}

	if (flag == 0) ///���� ���������� ���

	{

		printf("| |\n"

			"| ���������� ��� |\n"

			"|___________________________________________________________________________________________________________________________________________|\n");

		break;

	}

	printf("\n");

	break;

	}

	}

}

int edit(char* name) ///�������������� �������� ������ � ����

{
	FILE* f;

	Ship ship;

	int p;

	if ((f = fopen(name, "r+b")) == NULL)

	{

		printf("error1\n");

		return(-1);

	}

	int num, last, if_show;

	printf("����� ���������� ������ ������ ������� 1\n"

		"����� ���������� ��� ������ ������� 0\n");

	scanf("%d", &if_show);

	while ((if_show != 1) && (if_show != 0))

	{

		printf("����� ���������� ������ ������ ������� 1\n"

			"����� ���������� ��� ������ ������� 0\n");

		scanf("%d", &if_show);

	}

	if (if_show) show(name);

	printf("������� ����� �������, ����� �������� ������ �� ����: ");

	while ((scanf("%d", &num) == 0) || (num <= 0))

	{

		printf("������������ ����\n");

		printf("������� ����� �������, ����� �������� ������ �� ����: ");

	}

	fseek(f, 0, SEEK_END);

	last = ftell(f) / sizeof(Ship); ///������� ���-�� ������� � ����

	while ((num > last) || (num <= 0)) ///��������, ���� �� � ���� ������ � ������ �������

	{

		printf("� ���� ��� ������� � ������� %d, ������� ��� ���:\n", num);

		while ((scanf("%d", &num) == 0) || (num <= 0))

		{

			printf("������������ ����\n");

			printf("������� ����� �������, ����� �������� ������ �� ����: ");

		}

	}

	printf("\n�������� ���� ��� ��������������:\n");
	printf("1. ��� ��������\n");

	printf("2. ������\n");

	printf("3. ��� ���������\n");

	printf("4. ����� ���������\n");

	printf("5. �������� �����\n");

	printf("6. �������������\n");

	printf("7. ��� �������\n");

	printf("8. �����������\n");

	printf("> ");

	scanf("%d", &p);

	while ((p == 0) || (p <= 0) && (p > 4))

	{

		printf("\n������������ ����\n"

			"�������� ���� ��� ������:\n"

			">");

		scanf("%d", &p);

	}

	fseek(f, (num - 1) * sizeof(Ship), SEEK_SET); ///��������� �� ������ ������ �� ����

	fread(&ship, 1, sizeof(Ship), f); ///��������� ��

	printf("������� ������: \n");

	rewind(stdin);

	switch (p)

	{

	case 1:

	{

		gets(ship.name);

		while (checkstr(ship.name))

		{

			printf("������ �������� ������������ �������\n");

			printf("���: ");

			gets(ship.name);

		}

		printf("������ ������� ��������\n");

		break;

	}

	case 2:

	{

		gets(ship.country);

		while (checkstr(ship.country))

		{

			printf("������ �������� ������������ �������\n");

			printf("������: ");

			gets(ship.country);

		}

		printf("������ ������� ��������.\n");

		break;

	}

	case 3:

	{

		scanf("%d", &(ship.year));

		while (ship.year < 0)

		{

			printf("������������ ����\n");

			printf("��� ���������: ");

			scanf("%d", &(ship.year));

		}

		printf("������ ������� ��������.\n");

		break;

	}

	case 4:

	{

		scanf("%d", &(ship.summa));

		while (ship.summa < 0)

		{

			printf("������������ ����\n");

			printf("����� ���������: ");

			scanf("%d", &(ship.summa));

		}

		printf("������ ������� ��������.\n");

		break;

	}
	case 5:

	{

		gets(ship.sudno);

		while (checkstr(ship.sudno))

		{

			printf("������ �������� ������������ �������\n");

			printf("�������� �����: ");

			gets(ship.sudno);

		}

		printf("������ ������� ��������\n");

		break;

	}
	case 6:

	{

		scanf("%d", &(ship.water));

		while (ship.water < 0)

		{

			printf("������������ ����\n");

			printf("�������������: ");

			scanf("%d", &(ship.year));

		}

		printf("������ ������� ��������.\n");

		break;

	}
	case 7:

	{
		int k;
		printf("������� ��� ������� 1.������ 2.�������� 3.������������\n");
		scanf("%d", &k);

		while ((k <= 0) || (k > 3)) {
			printf("\n������������ ����\n�������� ��� �������:\n");
			scanf("%d", &k);
		}

		switch (k) {
		case 1:
			strcpy(ship.type, "Tanker");
			break;
		case 2:
			strcpy(ship.type, "Suhogruz");
			break;
		case 3:
			strcpy(ship.type, "Passazhirskiy");
			break;
		}
		getchar();

		printf("������ ������� ��������\n");

		break;

	}
	case 8:

	{	int h;

	printf("������� �������������� ����������� 1.�� 2.���\n");
	scanf("%d", &h);

	while ((h <= 0) || (h > 2)) {
		printf("\n������������ ����\n�������� �������������� ������������:\n");
		scanf("%d", &h);
	}

	switch (h) {
	case 1:
		strcpy(ship.shipping, "Yes");
		break;
	case 2:
		strcpy(ship.shipping, "No");
		break;
	}
	getchar();

		printf("������ ������� ��������\n");

		break;

	}

	}

	fseek(f, (num - 1) * sizeof(Ship), SEEK_SET); ///����� ������ �� ������ ������

	fwrite(&ship, sizeof(Ship), 1, f); ///���������� ���������� ������ � ����

	fclose(f);

	return 0;

}

int sort(char* name) ///���������� ������ � ���� �� ��������� ����

{

	FILE* f;

	if ((f = fopen(name, "r+b")) == NULL)

	{

		printf("error1\n");

		return(-1);

	}

	int i, j, k, size, p;

	fseek(f, 0, SEEK_END);

	size = ftell(f) / sizeof(Ship); ///������� ���-�� ������� � ����

	rewind(f);

	Ship* ship = (Ship*)malloc(size * sizeof(Ship)); ///������ ��������

	Ship tmp;

	for (i = 0; i < size; i++)

	fread(&ship[i], 1, sizeof(Ship), f); ///��������� �� ����� ������ ��������

	printf("\n�������� ���� ��� ����������:\n");

	printf("1. ��� ��������\n");

	printf("2. ������\n");

	printf("3. ��� ���������\n");

	printf("4. ����� ���������\n");

	printf("5. �������� �����\n");

	printf("6. �������������\n");

	printf("7. ��� �������\n");

	printf("8. �����������\n");

	printf("> ");

	while ((scanf("%d", &p) == 0) || (p <= 0) || (p > 8))

	{

		printf("\n������������ ����\n"

			"�������� ���� ��� ����������:\n"

			">");

	}

	int flag = 0; ///���������� ������(��� ���)

	switch (p)

	{

	case 1:

	{

		for (i = size - 1; i >= 0; i--) ///���������� ���������, i � �����, �� ��������������� ����� �������

		{

			for (j = 0; j < i; j++)

			{

				if (strcmp(ship[j].name, ship[j + 1].name) > 0) ///��������� �����

				{

					tmp = ship[j];

					ship[j] = ship[j + 1];

					ship[j + 1] = tmp;

					flag++;

				}

			}

		}

		if (flag > 0)

			printf("���������� ������ �������\n");

		else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

		break;

	}

	case 2: 

	{

		for (i = size - 1; i >= 0; i--)

		{

			for (j = 0; j < i; j++)

			{

				if (strcmp(ship[j].country, ship[j + 1].country) > 0)

				{

					tmp = ship[j];

					ship[j] = ship[j + 1];

					ship[j + 1] = tmp;

					flag++;

				}

			}

		}

		if (flag > 0)

			printf("���������� ������ �������\n");

		else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

		break;

	}

	case 3: ///(����������� ��� ��������� � ����������� �� ����������� ��� ��������)

	{

		printf("1. �� �����������\n"

			"2. �� ��������\n"

			"> ");

		while ((scanf("%d", &k) == 0) || (k != 1) && (k != 2))

		{

			printf("������������ ����\n"

				"��������� �������\n");

			printf("> ");

		}

		printf("\n");

		switch (k)

		{

		case 1:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (ship[j].year > ship[j + 1].year)

					{

						tmp = ship[j];

						ship[j] = ship[j + 1];

						ship[j + 1] = tmp;

						flag++;

					}

				}

			}

			if (flag > 0)

				printf("���������� ������ �������\n");

			else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

			break;

		case 2:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (ship[j].year < ship[j + 1].year)

					{

						tmp = ship[j];

						ship[j] = ship[j + 1];

						ship[j + 1] = tmp;

						flag++;

					}

				}

			}

			if (flag > 0)

				printf("���������� ������ �������\n");

			else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

			break;

		}

		break;

	}

	case 4: ///(���������� �������� ������)

	{

		printf("1. �� �����������\n"

			"2. �� ��������\n"

			"> ");

		while ((scanf("%d", &k) == 0) || (k != 1) && (k != 2))

		{

			printf("������������ ����\n"

				"��������� �������\n");

			printf("> ");

		}

		printf("\n");

		switch (k)

		{

		case 1:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (ship[j].summa > ship[j + 1].summa)

					{

						tmp = ship[j];

						ship[j] = ship[j + 1];

						ship[j + 1] = tmp;

						flag++;

					}

				}

			}

			if (flag > 0)

				printf("���������� ������ �������\n");

			else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

			break;

		case 2:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (ship[j].summa < ship[j + 1].summa)

					{

						tmp = ship[j];

						ship[j] = ship[j + 1];

						ship[j + 1] = tmp;

						flag++;

					}

				}

			}

			if (flag > 0)

				printf("���������� ������ �������\n");

			else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

			break;

		}

		break;

	}



	case 5:

	{

		for (i = size - 1; i >= 0; i--) ///���������� ���������, i � �����, �� ��������������� ����� �������

		{

			for (j = 0; j < i; j++)

			{

				if (strcmp(ship[j].sudno, ship[j + 1].sudno) > 0) ///��������� �����

				{

					tmp = ship[j];

					ship[j] = ship[j + 1];

					ship[j + 1] = tmp;

					flag++;

				}

			}

		}

		if (flag > 0)

			printf("���������� ������ �������\n");

		else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

		break;

	}

	case 6: ///(���������� �������� ������)


	{

		printf("1. �� �����������\n"

			"2. �� ��������\n"

			"> ");

		while ((scanf("%d", &k) == 0) || (k != 1) && (k != 2))

		{

			printf("������������ ����\n"

				"��������� �������\n");

			printf("> ");

		}

		printf("\n");

		switch (k)

		{

		case 1:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (ship[j].water > ship[j + 1].water)

					{

						tmp = ship[j];

						ship[j] = ship[j + 1];

						ship[j + 1] = tmp;

						flag++;

					}

				}

			}

			if (flag > 0)

				printf("���������� ������ �������\n");

			else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

			break;

		case 2:

			for (i = size - 1; i >= 0; i--)

			{

				for (j = 0; j < i; j++)

				{

					if (ship[j].water < ship[j + 1].water)

					{

						tmp = ship[j];

						ship[j] = ship[j + 1];

						ship[j + 1] = tmp;

						flag++;

					}

				}

			}

			if (flag > 0)

				printf("���������� ������ �������\n");

			else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

			break;

		}

		break;

	}


	case 7:

	{

		for (i = size - 1; i >= 0; i--) ///���������� ���������, i � �����, �� ��������������� ����� �������

		{

			for (j = 0; j < i; j++)

			{

				if (strcmp(ship[j].type, ship[j + 1].type) > 0) ///��������� �����

				{

					tmp = ship[j];

					ship[j] = ship[j + 1];

					ship[j + 1] = tmp;

					flag++;

				}

			}

		}

		if (flag > 0)

			printf("���������� ������ �������\n");

		else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

		break;

	}

	case 8:

	{

		for (i = size - 1; i >= 0; i--) ///���������� ���������, i � �����, �� ��������������� ����� �������

		{

			for (j = 0; j < i; j++)

			{

				if (strcmp(ship[j].shipping, ship[j + 1].shipping) > 0) ///��������� �����

				{

					tmp = ship[j];

					ship[j] = ship[j + 1];

					ship[j + 1] = tmp;

					flag++;

				}

			}

		}

		if (flag > 0)

			printf("���������� ������ �������\n");

		else printf("�� �������� ������. ��� ����������. (�������� ������ ��� ������������ ��� �������� ������)\n");

		break;

	}

	}

	rewind(f);

	for (i = 0; i < size; i++) ///���������� ���������� ������

	{

		fwrite(&ship[i], sizeof(Ship), 1, f);

	}

	free(ship); ///����������� ������ ��������

	fclose(f);

	return 0;

}


int show(char* name) ///����� ����

{

	FILE* f;

	Ship ship;

	if ((f = fopen(name, "rb")) == NULL)

	{

		printf("error1\n");

		return(-1);

	}

	int i = 1;

	printf("���� ������ ��������:\n\n");

	printf(" ____________________________________________________________________________________________________________________________________ \n");

	printf("| | | | | |\n");

	printf("| � |    �������     |     ������    |     ���    | ��������� |          �����       | �������������  | ��� �������   |  �����������|\n");

	printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

	while (!feof(f)) ///���� �� ����� �����

	{

		fread(&ship, sizeof(Ship), 1, f); ///��������� ������ �� ����� ������

		if (!feof(f))

		{
			printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

			i++;

			printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		}

	}

	printf("\n");

	fclose(f);

	return 0;

}

int main()

{

	int c, exit = 0;

	char data[] = "data";

	setlocale(LC_ALL, "RUS");

	while (!exit)

	{

		system("cls");

		printf("���� ������ � ��������\n\n"

			"�������� ��������:\n"

			"1) ���������� ���� ������\n"

			"2) ���������� ������ � ����\n"

			"3) �������� �������� ������ �� ����\n"

			"4) ����� ������ �� ��������� ����\n"

			"5) �������������� �������� ������ � ����\n"

			"6) ���������� ������ � ���� �� ��������� ����\n"

			"7) ����� �� ����� ����������� ���� � ��������� ����\n"

			"0) �����\n\n"

			"> ");

		while ((scanf("%d", &c) == 0) || (c > 7) || (c < 0))

		{

			printf("������������ ����\n"

				"�������� ��������:\n"

				"> ");

		}

		switch (c)
		{

		case 1: fill(data); break;

		case 2: add(data); break;

		case 3: delete_f(data); break;

		case 4: search(data); break;

		case 5: edit(data); break;

		case 6: sort(data); break;

		case 7: show(data); break;

		case 0: exit = 1; break;

		}

		system("pause");

	}
	return 0;

}