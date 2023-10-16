#ifndef Ship_h

#define Ship_H

typedef struct /// описание структуры

{

	char name[20]; /// фио капитана

	char sudno[20];

	char country[20]; 

	int year; 

	int water; 
	
	int summa;

	char shipping[8];

	char type[15];


}Ship;

int checkstr(char* str); /// Проверка корректности введенной строки

int fill(char* name); /// Заполнение базы данных

int add(char* name); /// Добавление записи в базу

int delete_f(char* name); /// Удаление заданной записи из базы

int search(char* name); /// Поиск записи по заданному полю

int edit(char* name); /// Редактирование заданной записи в базе

int sort(char* name); /// Сортировка данных в базе по заданному полю

int show(char* name); /// Вывод на экран содержимого базы

#endif