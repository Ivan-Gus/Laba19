#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES 

struct Car {
	char mark[50];         // Марка автомобиля
	char pr[50];  // Производитель
	char type[30];          // Тип 
	int god;               // Год выпуска
	char data[11];      // Дата регистрации 
};

int main(void) {
	setlocale(LC_CTYPE, "RUS");
	struct Car car;
	FILE* file;
	printf("Введите марку автомобиля: ");
	fgets(car.mark, sizeof(car.mark), stdin);
	printf("Введите производителя автомобиля: ");
	fgets(car.pr, sizeof(car.pr), stdin);
	printf("Введите тип автомобиля: ");
	fgets(car.type, sizeof(car.type), stdin);
	printf("Введите год выпуска автомобиля: ");
	fgets(car.god, sizeof(car.god), stdin);
	printf("Введите дату регистрации автомобиля: ");
	fgets(car.data, sizeof(car.data), stdin);
	file = fopen("car.txt", "wt");
	if (file == NULL) {
		printf("Ошибка открытия файла\n");
		return 1;
	}

	
	fprintf(file,"Марка: %s\n", car.mark);
	fprintf(file,"Производитель: %s\n", car.pr);
	fprintf(file,"Тип: %s\n", car.type);
	fprintf(file,"Год выпуска: %d\n", car.god);
	fprintf(file,"Дата регистрации: %s\n", car.data);
	
	fclose(file);
	return 0;
}

