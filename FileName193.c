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
	int vep;               // Год выпуска
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
	printf("Введите дату регистрации автомобиля: ");
	fgets(car.data, sizeof(car.data), stdin);
	printf("Введите год выпуска автомобиля: ");
	scanf("%d", &car.vep);
	file = fopen("car.txt", "wt");
	if (file == NULL) {
		printf("Ошибка открытия файла\n");
		return 1;
	}


	fprintf(file, "Марка: %s", car.mark);
	fprintf(file, "Производитель: %s", car.pr);
	fprintf(file, "Тип: %s", car.type);
	fprintf(file, "Год выпуска: %d\n", car.vep);
	fprintf(file, "Дата регистрации: %s", car.data);

	fclose(file);
	printf("Данные успешно записаны в файл 'car.txt'\n");
	return 0;
}

