#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <malloc.h>
#include "H.h"

int checkstr(char* str) ///проверка корректности введенной строки
{

	///Функция isspace(ch) возвращает ненулевое значение, если аргумент ch является пробельным символом, в противном случае возвращается нуль

	///Функция isalpha(ch) возвращает ненулевое значение, если ее аргумент ch является буквой, в противном случае возвращается нуль

	for (int i = 0; i < strlen(str); i++)
		if ((isspace(str[i]) == 0) && (isalpha(str[i]) == 0) && (str[i] != '.'))
		{
			return 1;
		}

	return 0;

}

int fill(char* name) ///Заполнение базы данных

{

	FILE* f;

	Ship ship;

	int n;
	int p;
	int k;
	char clear;

	printf("\nВведите количество кораблей: ");

	while ((scanf("%d", &n) == 0) || (n <= 0))

	{

		printf("Некорректный ввод\n");

		printf("\nВведите количество кораблей: ");

	}

	if ((f = fopen(name, "wb")) == NULL) ///проверка, что файл успешно создан

	{

		printf("error1\n");

		return(-1);

	}

	for (int i = 0; i < n; i++) ///ввод данных

	{
		p = 0;
		rewind(stdin);

		printf("\nВведите данные %d-ого корабля:\n", i + 1);

		printf("ФИО капитана: ");

		gets(ship.name);

		while (checkstr(ship.name))

		{

			printf("Строка содержит недопустимые символы\n");

			printf("ФИО капитана: ");

			gets(ship.name);

		}

		printf("Название судна: ");

		gets(ship.sudno);

		while (checkstr(ship.sudno))

		{

			printf("Строка содержит недопустимые символы\n");

			printf("ФИО капитана: ");

			gets(ship.sudno);

		}

		printf("Страна: ");

		gets(ship.country);

		while (checkstr(ship.country))

		{

			printf("Строка содержит недопустимые символы\n");

			printf("Страна постройки: ");

			gets(ship.country);

		}


		printf("Принадлежность пароходству 1.Да 2.Нет\n");
		scanf("%d", &p);

		while ((p <= 0) || (p > 2)) {
			printf("\nНекорректный ввод\nВыберите принадлежность пароходсмтву:\n");
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
		printf("Введите тип корабля 1.Танкер 2.Сухогруз 3.Пассажирский\n");
		scanf("%d", &k);

		while ((k <= 0) || (k > 3)) {
			printf("\nНекорректный ввод\nВыберите тип корабля:\n");
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
		
		printf("Год постройки: ");

		scanf("%d", &(ship.year));

		while (ship.year < 0)

		{

			printf("Неккоректный ввод\n");

			printf("Год постройки: ");

			scanf("%d", &(ship.year));

		}
		printf("Сумма страховки: ");

		scanf("%d", &(ship.summa));

		

		while (ship.summa < 0)

		{

			printf("Некорректный ввод\n");

			printf("Сумма страховки: ");

			scanf("%d", &(ship.summa));

		}

		printf("Водоизмещение: ");

		scanf("%d", &(ship.water));

		

		while (ship.water < 0)

		{

			printf("Некорректный ввод\n");

			printf("Водоизмещение: ");

			scanf("%d", &(ship.water));

		}


		fwrite(&ship, sizeof(ship), 1, f); ///Записываем данные команды в файл

	}

	printf("\nБаза данных о студентах успешно заполнена\n\n");

	fclose(f);

	return 0;

}

int add(char* name){///Добавление записи в базу
	int p,k;
	FILE* f;

	Ship ship;

	if ((f = fopen(name, "ab")) == NULL) ///открываем файл для до записи

	{

		printf("error1\n");

		return(-1);

	}


	printf("Введите данные корабля:\n");

	printf("ФИО капитана: ");

	getchar();

	gets(ship.name);

	while (checkstr(ship.name))

	{

		printf("Строка содержит недопустимые символы\n");

		printf("ФИО капитана: ");

		gets(ship.name);

	}


	printf("Название судна: ");

	gets(ship.sudno);

	while (checkstr(ship.sudno))

	{

		printf("Строка содержит недопустимые символы\n");

		printf("ФИО капитана: ");

		gets(ship.sudno);

	}

	fflush(stdin);

	printf("Страна: ");

	gets(ship.country);

	while (checkstr(ship.country))

	{

		printf("Строка содержит недопустимые символы\n");

		printf("Страна постройки: ");

		gets(ship.country);

	}

	printf("Год постройки: ");

	scanf("%d", &(ship.year));

	

	while (ship.year < 0)

	{

		printf("Неккоректный ввод\n");

		printf("Год постройки: ");

		scanf("%d", &(ship.year));

	}

	printf("Водоизмещение: ");
	scanf("%d", &(ship.water));


	while (ship.water < 0)
	{
		printf("Некорректный ввод\n");

		printf("Водоизмещение: ");

		scanf("%d", &(ship.water));

	}

	printf("Сумма страховки: ");

	scanf("%d", &(ship.summa));


	while (ship.summa < 0)

	{

		printf("Некорректный ввод\n");

		printf("Сумма страховки: ");

		scanf("%d", &(ship.summa));

	}


	printf("Принадлежность пароходству 1.Да 2.Нет\n");
	scanf("%d", &p);

	while ((p <= 0) || (p > 2)) {
		printf("\nНекорректный ввод\nВыберите принадлежность параходсмтву:\n");
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

	printf("Введите тип корабля 1.Танкер 2.Сухогруз 3.Пассажирский\n");

	scanf("%d", &k);

	while ((k <= 0) || (k > 3)) {
		printf("\nНекорректный ввод\nВыберите тип корабля:\n");
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

	printf("\nЗапись добавлена\n\n");

	fclose(f);

	return 0;

}

int delete_f(char* name) ///Удаление заданной записи из базы

{

	FILE* f;

	Ship ship;

	if ((f = fopen(name, "r+b")) == NULL) ///чтение и запись

	{

		printf("error1\n");

		return(-1);

	}

	int num, last, if_show;

	printf("Чтобы посмотреть список команд введите 1\n"

		"Чтобы продолжить без списка введите 0\n");

	scanf("%d", &if_show);

	while ((if_show != 1) && (if_show != 0)) ///неправильный ввод
	{
		printf("Чтобы посмотреть список команд введите 1\n"

			"Чтобы продолжить без списка введите 0\n");

		scanf("%d", &if_show);
	}
	if (if_show) show(name);

	printf("Введите номер корабля, чтобы удалить данные из базы: ");

	while ((scanf("%d", &num) == 0) || (num <= 0))

	{
		printf("Некорректный ввод\n");

		printf("Введите номер корабля, чтобы удалить данные из базы: ");
	}

	fseek(f, 0, SEEK_END); /// Считаем кол-во записей в базе

	last = ftell(f) / sizeof(Ship);

	if (num > last) /// Проверка, есть ли в базе запись с данным номером

	{

		printf("В базе нет команды с номером %d, введите еще раз:\n", num);

		while ((scanf("%d", &num) == 0) || (num <= 0) || (num > last))

		{

			printf("Некорректный ввод\n");

			printf("Введите номер корабля, чтобы удалить данные из базы: ");

		}

	}

	for (int i = num - 1; i < last - 1; i++) ///Изначально встаем перед элементом, который надо удалить
	{
		fseek(f, (i + 1) * sizeof(Ship), SEEK_SET);

		fread(&ship, sizeof(Ship), 1, f); ///Считываем следующий элемент

		fseek(f, i * sizeof(Ship), SEEK_SET); ///Возвращаемся назад

		fwrite(&ship, sizeof(Ship), 1, f); ///Записываем следующий элемент вместо текущего

	}

	if (_chsize(_fileno(f), (last - 1) * sizeof(Ship)) == 0) /// Уменьшаем размер файла

		printf("Запись удалена\n\n");

	else printf("Ошибка уменьшения размера\n");

	fclose(f);

	return 0;

}

int search(char* name) ///Поиск записи по заданному полю

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

	printf("\nВыберите поле для поиска:\n");

	printf("1. ФИО капитана\n");

	printf("2. Страна\n");

	printf("3. Год постройки\n");

	printf("4. Сумма страховки\n");

	printf("5. Название судна\n");

	printf("6. Водоизмещение\n");

	printf("7. Тип корабля\n");

	printf("8. Пароходство\n");


	printf("> ");

	while ((scanf("%d", &p) == 0) || (p <= 0) || (p > 8))

	{

		printf("\nНекорректный ввод\n"

			"Выберите поле для поиска:\n"

			">");

	}

	switch (p)

	{

	case 1:

	{

		i = 1;

		flag = 0; ///переменная для наличия совпадений

		printf("Введите ФИО капитана: ");

		rewind(stdin);

		gets(str);

		printf(" ___________________________________________________________________________________________________________________________________ \n");


		printf("| № |    Капитан     |     Страна    |     Год    | Страховка |          Судно       | Водоизмезение  | Тип корабля   |  Пароходство|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///Пока не конец файла

		{

			fread(&ship, sizeof(Ship), 1, f); ///Считываем данные одной записи

			if (!feof(f) && !strcmp(ship.name, str)) ///Если найдено совпадение

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///Если совпадений нет

		{

			printf("| |\n"

				"| Совпадений нет |\n"

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

		printf("Введите страну: ");

		rewind(stdin);

		gets(str);

		printf(" ___________________________________________________________________________________________________________________________________\n");

		printf("| | | | | | | | | |\n");

		printf("| № |    Капитан     |     Страна    |     Год    | Страховка |          Судно       | Водоизмезение  | Тип корабля   |  Пароходство|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///Пока не конец файла

		{

			fread(&ship, sizeof(Ship), 1, f); ///Считываем данные одной записи

			if (!feof(f) && !strcmp(ship.country, str)) ///Если найдено совпадение

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///Если совпадений нет

		{

			printf("| |\n"

				"| Совпадений нет |\n"

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

		printf("Введите год постройки : ");

		int year = 0;

		scanf("%d", &year);

		while (year < 0)

		{

			printf("Некорректный ввод\n");

			printf("Введите год постройки: ");

			scanf("%d", &year);

		}

		printf(" ___________________________________________________________________________________________________________________________________\n");

		printf("| | | | | | | | | |\n");

		printf("| № |    Капитан     |     Страна    |     Год    | Страховка |          Судно       | Водоизмезение  | Тип корабля   |  Пароходство|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///Пока не конец файла

		{

			fread(&ship, sizeof(Ship), 1, f); ///Считываем данные по одной записи

			if (!feof(f) && (ship.year == year)) ///Если найдено совпадение

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///Если совпадений нет

		{

			printf("| |\n"

				"| Совпадений нет |\n"

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

		printf("Введите сумма страховки  : ");

		int summ = 0;

		scanf("%d", &summ);

		while (summ < 0)

		{

			printf("Некорректный ввод\n");

			printf("Введите сумму страховки: ");

			scanf("%d", &summ);

		}

		printf(" ___________________________________________________________________________________________________________________________________\n");

		printf("| | | | | | | | | |\n");

		printf("| № |    Капитан     |     Страна    |     Год    | Страховка |          Судно       | Водоизмезение  | Тип корабля   |  Пароходство|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");
		while (!feof(f)) ///Пока не конец файла

		{

			fread(&ship, sizeof(Ship), 1, f); ///Считываем данные по одной записи

			if (!feof(f) && (ship.summa == summ)) ///Если найдено совпадение

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///Если совпадений нет

		{

			printf("| |\n"

				"| Совпадений нет |\n"

				"|____________________________________________________________________________________________________________________________________________|\n");

			break;

		}

		printf("\n");

		break;

	}

	case 5:
	{
		i = 1;

		flag = 0; ///переменная для наличия совпадений

		printf("Введите название судна: ");

		rewind(stdin);

		gets(str);

		printf(" ___________________________________________________________________________________________________________________________________ \n");

		printf("| | | | | |\n");

		printf("| № |    Капитан     |     Страна    |     Год    | Страховка |          Судно       | Водоизмезение  | Тип корабля   |  Пароходство|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///Пока не конец файла

		{

			fread(&ship, sizeof(Ship), 1, f); ///Считываем данные одной записи

			if (!feof(f) && !strcmp(ship.sudno, str)) ///Если найдено совпадение

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///Если совпадений нет

		{

			printf("| |\n"

				"| Совпадений нет |\n"

				"|_______________________________________________________________________________________________________________________________________________|\n");

			break;

		}

		break;

	}

	


	case 6:

	{

		i = 1;

		flag = 0;

		printf("Введите водоизмещение : ");

		int waterp = 0;

		scanf("%d", &waterp);

		while (waterp < 0)

		{

			printf("Некорректный ввод\n");

			printf("Введите сумму страховки: ");

			scanf("%d", &waterp);

		}

		printf(" ____________________________________________________________________________________________________________________________________\n");

		printf("| | | | | | | | | |\n");

		printf("| № |    Капитан     |     Страна    |     Год    | Страховка |          Судно       | Водоизмезение  | Тип корабля   |  Пароходство|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");
		while (!feof(f)) ///Пока не конец файла

		{

			fread(&ship, sizeof(Ship), 1, f); ///Считываем данные по одной записи

			if (!feof(f) && (ship.water == waterp)) ///Если найдено совпадение

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///Если совпадений нет

		{

			printf("| |\n"

				"| Совпадений нет |\n"

				"|____________________________________________________________________________________________________________________________________________|\n");

			break;

		}
		break;
	}


	case 7:
	{
		i = 1;
		

		flag = 0; ///переменная для наличия совпадений

		printf("Введите тип судна: ");

		rewind(stdin);

		gets(str);

		printf(" ____________________________________________________________________________________________________________________________________ \n");

		printf("| | | | | |\n");

		printf("| № |    Капитан     |     Страна    |     Год    | Страховка |          Судно       | Водоизмезение  | Тип корабля   |  Пароходство|\n");

		printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

		while (!feof(f)) ///Пока не конец файла

		{

			fread(&ship, sizeof(Ship), 1, f); ///Считываем данные одной записи

			if (!feof(f) && !strcmp(ship.type, str)) ///Если найдено совпадение

			{

				printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

				i++;

				printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

			}

		}

		if (flag == 0) ///Если совпадений нет

		{

			printf("| |\n"

				"| Совпадений нет |\n"

				"|______________________________________________________________________________________________________________________________________________|\n");

			break;

		}

		printf("\n");

		break;
	}

	case 8:
	{i = 1;

	flag = 0; ///переменная для наличия совпадений
	
	printf("Введите принадлежность к судоходству: ");

	rewind(stdin);

	gets(str);

	printf(" ___________________________________________________________________________________________________________________________________ \n");

	printf("| | | | | |\n");

	printf("| № |    Капитан     |     Страна    |     Год    | Страховка |          Судно       | Водоизмезение  | Тип корабля   |  Пароходство|\n");

	printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

	while (!feof(f)) ///Пока не конец файла

	{

		fread(&ship, sizeof(Ship), 1, f); ///Считываем данные одной записи

		if (!feof(f) && !strcmp(ship.shipping, str)) ///Если найдено совпадение

		{

			printf("|%-3d|%-16s|%-15s|%-12d|%-11d|%-22s|%-16d|%-15s|%-13s|", i, ship.name, ship.country, ship.year, ship.summa, ship.sudno, ship.water, ship.type, ship.shipping);

			i++;

			printf("\n|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n"); flag = 1;

		}

	}

	if (flag == 0) ///Если совпадений нет

	{

		printf("| |\n"

			"| Совпадений нет |\n"

			"|___________________________________________________________________________________________________________________________________________|\n");

		break;

	}

	printf("\n");

	break;

	}

	}

}

int edit(char* name) ///Редактирование заданной записи в базе

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

	printf("Чтобы посмотреть список команд введите 1\n"

		"Чтобы продолжить без списка введите 0\n");

	scanf("%d", &if_show);

	while ((if_show != 1) && (if_show != 0))

	{

		printf("Чтобы посмотреть список команд введите 1\n"

			"Чтобы продолжить без списка введите 0\n");

		scanf("%d", &if_show);

	}

	if (if_show) show(name);

	printf("Введите номер корабля, чтобы изменить данные из базы: ");

	while ((scanf("%d", &num) == 0) || (num <= 0))

	{

		printf("Некорректный ввод\n");

		printf("Введите номер корабля, чтобы изменить данные из базы: ");

	}

	fseek(f, 0, SEEK_END);

	last = ftell(f) / sizeof(Ship); ///Считаем кол-во записей в базе

	while ((num > last) || (num <= 0)) ///Проверка, есть ли в базе запись с данным номером

	{

		printf("В базе нет команды с номером %d, введите еще раз:\n", num);

		while ((scanf("%d", &num) == 0) || (num <= 0))

		{

			printf("Некорректный ввод\n");

			printf("Введите номер корабля, чтобы изменить данные из базы: ");

		}

	}

	printf("\nВыберите поле для редактирования:\n");
	printf("1. ФИО капитана\n");

	printf("2. Страна\n");

	printf("3. Год постройки\n");

	printf("4. Сумма страховки\n");

	printf("5. Название судна\n");

	printf("6. Водоизмещение\n");

	printf("7. Тип корабля\n");

	printf("8. Пароходство\n");

	printf("> ");

	scanf("%d", &p);

	while ((p == 0) || (p <= 0) && (p > 4))

	{

		printf("\nНекорректный ввод\n"

			"Выберите поле для поиска:\n"

			">");

		scanf("%d", &p);

	}

	fseek(f, (num - 1) * sizeof(Ship), SEEK_SET); ///Смещаемся на нужную запись из базы

	fread(&ship, 1, sizeof(Ship), f); ///Считываем ее

	printf("Введите данные: \n");

	rewind(stdin);

	switch (p)

	{

	case 1:

	{

		gets(ship.name);

		while (checkstr(ship.name))

		{

			printf("Строка содержит недопустимые символы\n");

			printf("ФИО: ");

			gets(ship.name);

		}

		printf("Запись успешно изменена\n");

		break;

	}

	case 2:

	{

		gets(ship.country);

		while (checkstr(ship.country))

		{

			printf("Строка содержит недопустимые символы\n");

			printf("Страна: ");

			gets(ship.country);

		}

		printf("Запись успешно изменена.\n");

		break;

	}

	case 3:

	{

		scanf("%d", &(ship.year));

		while (ship.year < 0)

		{

			printf("Некорректный ввод\n");

			printf("Год постройки: ");

			scanf("%d", &(ship.year));

		}

		printf("Запись успешно изменена.\n");

		break;

	}

	case 4:

	{

		scanf("%d", &(ship.summa));

		while (ship.summa < 0)

		{

			printf("Некорректный ввод\n");

			printf("Сумма страховки: ");

			scanf("%d", &(ship.summa));

		}

		printf("Запись успешно изменена.\n");

		break;

	}
	case 5:

	{

		gets(ship.sudno);

		while (checkstr(ship.sudno))

		{

			printf("Строка содержит недопустимые символы\n");

			printf("Название судна: ");

			gets(ship.sudno);

		}

		printf("Запись успешно изменена\n");

		break;

	}
	case 6:

	{

		scanf("%d", &(ship.water));

		while (ship.water < 0)

		{

			printf("Некорректный ввод\n");

			printf("Водоизмещение: ");

			scanf("%d", &(ship.year));

		}

		printf("Запись успешно изменена.\n");

		break;

	}
	case 7:

	{
		int k;
		printf("Введите тип корабля 1.Танкер 2.Сухогруз 3.Пассажирский\n");
		scanf("%d", &k);

		while ((k <= 0) || (k > 3)) {
			printf("\nНекорректный ввод\nВыберите тип корабля:\n");
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

		printf("Запись успешно изменена\n");

		break;

	}
	case 8:

	{	int h;

	printf("Введите принадлежность пароходству 1.Да 2.Нет\n");
	scanf("%d", &h);

	while ((h <= 0) || (h > 2)) {
		printf("\nНекорректный ввод\nВыберите принадлежность пароходсмтву:\n");
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

		printf("Запись успешно изменена\n");

		break;

	}

	}

	fseek(f, (num - 1) * sizeof(Ship), SEEK_SET); ///Снова встаем на нужную запись

	fwrite(&ship, sizeof(Ship), 1, f); ///Записываем измененную запись в файл

	fclose(f);

	return 0;

}

int sort(char* name) ///Сортировка данных в базе по заданному полю

{

	FILE* f;

	if ((f = fopen(name, "r+b")) == NULL)

	{

		printf("error1\n");

		return(-1);

	}

	int i, j, k, size, p;

	fseek(f, 0, SEEK_END);

	size = ftell(f) / sizeof(Ship); ///Считаем кол-во записей в базе

	rewind(f);

	Ship* ship = (Ship*)malloc(size * sizeof(Ship)); ///Массив структур

	Ship tmp;

	for (i = 0; i < size; i++)

	fread(&ship[i], 1, sizeof(Ship), f); ///Считываем из файла массив структур

	printf("\nВыберите поле для сортировки:\n");

	printf("1. ФИО капитана\n");

	printf("2. Страна\n");

	printf("3. Год постройки\n");

	printf("4. Сумма страховки\n");

	printf("5. Название судна\n");

	printf("6. Водоизмещение\n");

	printf("7. Тип корабля\n");

	printf("8. Пароходство\n");

	printf("> ");

	while ((scanf("%d", &p) == 0) || (p <= 0) || (p > 8))

	{

		printf("\nНекорректный ввод\n"

			"Выберите поле для сортировки:\n"

			">");

	}

	int flag = 0; ///сортировка прошла(или нет)

	switch (p)

	{

	case 1:

	{

		for (i = size - 1; i >= 0; i--) ///сортировка пузырьком, i – длина, не отсортированной части массива

		{

			for (j = 0; j < i; j++)

			{

				if (strcmp(ship[j].name, ship[j + 1].name) > 0) ///сравнение строк

				{

					tmp = ship[j];

					ship[j] = ship[j + 1];

					ship[j + 1] = tmp;

					flag++;

				}

			}

		}

		if (flag > 0)

			printf("Сортировка прошла успешно\n");

		else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

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

			printf("Сортировка прошла успешно\n");

		else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

		break;

	}

	case 3: ///(добавляется два подслучая – сортировать по возрастанию или убыванию)

	{

		printf("1. По возрастанию\n"

			"2. По убыванию\n"

			"> ");

		while ((scanf("%d", &k) == 0) || (k != 1) && (k != 2))

		{

			printf("Некорректный ввод\n"

				"Повторите попытку\n");

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

				printf("Сортировка прошла успешно\n");

			else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

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

				printf("Сортировка прошла успешно\n");

			else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

			break;

		}

		break;

	}

	case 4: ///(аналогично третьему случаю)

	{

		printf("1. По возрастанию\n"

			"2. По убыванию\n"

			"> ");

		while ((scanf("%d", &k) == 0) || (k != 1) && (k != 2))

		{

			printf("Некорректный ввод\n"

				"Повторите попытку\n");

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

				printf("Сортировка прошла успешно\n");

			else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

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

				printf("Сортировка прошла успешно\n");

			else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

			break;

		}

		break;

	}



	case 5:

	{

		for (i = size - 1; i >= 0; i--) ///сортировка пузырьком, i – длина, не отсортированной части массива

		{

			for (j = 0; j < i; j++)

			{

				if (strcmp(ship[j].sudno, ship[j + 1].sudno) > 0) ///сравнение строк

				{

					tmp = ship[j];

					ship[j] = ship[j + 1];

					ship[j + 1] = tmp;

					flag++;

				}

			}

		}

		if (flag > 0)

			printf("Сортировка прошла успешно\n");

		else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

		break;

	}

	case 6: ///(аналогично третьему случаю)


	{

		printf("1. По возрастанию\n"

			"2. По убыванию\n"

			"> ");

		while ((scanf("%d", &k) == 0) || (k != 1) && (k != 2))

		{

			printf("Некорректный ввод\n"

				"Повторите попытку\n");

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

				printf("Сортировка прошла успешно\n");

			else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

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

				printf("Сортировка прошла успешно\n");

			else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

			break;

		}

		break;

	}


	case 7:

	{

		for (i = size - 1; i >= 0; i--) ///сортировка пузырьком, i – длина, не отсортированной части массива

		{

			for (j = 0; j < i; j++)

			{

				if (strcmp(ship[j].type, ship[j + 1].type) > 0) ///сравнение строк

				{

					tmp = ship[j];

					ship[j] = ship[j + 1];

					ship[j + 1] = tmp;

					flag++;

				}

			}

		}

		if (flag > 0)

			printf("Сортировка прошла успешно\n");

		else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

		break;

	}

	case 8:

	{

		for (i = size - 1; i >= 0; i--) ///сортировка пузырьком, i – длина, не отсортированной части массива

		{

			for (j = 0; j < i; j++)

			{

				if (strcmp(ship[j].shipping, ship[j + 1].shipping) > 0) ///сравнение строк

				{

					tmp = ship[j];

					ship[j] = ship[j + 1];

					ship[j + 1] = tmp;

					flag++;

				}

			}

		}

		if (flag > 0)

			printf("Сортировка прошла успешно\n");

		else printf("Не выполнен проход. Без сортировки. (Возможно список уже отсортирован или возникла ошибка)\n");

		break;

	}

	}

	rewind(f);

	for (i = 0; i < size; i++) ///Записываем измененную запись

	{

		fwrite(&ship[i], sizeof(Ship), 1, f);

	}

	free(ship); ///Освобождаем массив структур

	fclose(f);

	return 0;

}


int show(char* name) ///Вывод базы

{

	FILE* f;

	Ship ship;

	if ((f = fopen(name, "rb")) == NULL)

	{

		printf("error1\n");

		return(-1);

	}

	int i = 1;

	printf("База данных кораблей:\n\n");

	printf(" ____________________________________________________________________________________________________________________________________ \n");

	printf("| | | | | |\n");

	printf("| № |    Капитан     |     Страна    |     Год    | Страховка |          Судно       | Водоизмезение  | Тип корабля   |  Пароходство|\n");

	printf("|___|________________|_______________|____________|___________|______________________|________________|_______________|_____________|\n");

	while (!feof(f)) ///Пока не конец файла

	{

		fread(&ship, sizeof(Ship), 1, f); ///Считываем данные по одной записи

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

		printf("База данных о кораблях\n\n"

			"Выберите действие:\n"

			"1) Заполнение базы данных\n"

			"2) Добавление записи в базу\n"

			"3) Удаление заданной записи из базы\n"

			"4) Поиск записи по заданному полю\n"

			"5) Редактирование заданной записи в базе\n"

			"6) Сортировка данных в базе по заданному полю\n"

			"7) Вывод на экран содержимого базы в табличном виде\n"

			"0) Выйти\n\n"

			"> ");

		while ((scanf("%d", &c) == 0) || (c > 7) || (c < 0))

		{

			printf("Некорректный ввод\n"

				"Выберите действие:\n"

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