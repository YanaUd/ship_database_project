#ifndef Ship_h

#define Ship_H

typedef struct /// �������� ���������

{

	char name[20]; /// ��� ��������

	char sudno[20];

	char country[20]; 

	int year; 

	int water; 
	
	int summa;

	char shipping[8];

	char type[15];


}Ship;

int checkstr(char* str); /// �������� ������������ ��������� ������

int fill(char* name); /// ���������� ���� ������

int add(char* name); /// ���������� ������ � ����

int delete_f(char* name); /// �������� �������� ������ �� ����

int search(char* name); /// ����� ������ �� ��������� ����

int edit(char* name); /// �������������� �������� ������ � ����

int sort(char* name); /// ���������� ������ � ���� �� ��������� ����

int show(char* name); /// ����� �� ����� ����������� ����

#endif