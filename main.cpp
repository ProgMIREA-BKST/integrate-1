#include <iostream>
#include <stdio.h>
float f1(float x) {
	return pow(2, x);
}

float f2(float x) {
	return 5*x+10;
}
float rectIntegrate(int x1, int x2, float dx, float f(float)) {
	float I = 0;//результат интегрирования
	int N = (int)(x2 - x1) / dx;//Количество шагов
	for (int i = 0; i < N; i++) {
		I += f(x1 + dx * i) * dx; //площадь прямоугольника
	}
	return I;
}

float trapIntegrate(int x1, int x2, float dx, float f(float)) {
	float I = 0;//результат интегрирования
	int N = (int)(x2 - x1) / dx;//Количество шагов
	for (int i = 0; i < N; i++) {
		I += (f(x1 + dx * i) + f(x1 + dx * (i + 1))) * dx / 2; //площадь трапеции
	}
	return I;
}
int main()
{
	setlocale(LC_ALL, "rus");
	//Пределы интегрирования
	int x1 = 0;
	int x2 = 5;
	float dx = 0.1;//Дискретность

    std::cout << "Интегралы :\n";
	float I = rectIntegrate(x1, x2, dx, f1);
	printf("функция 1: метод прямоугольников: %f\n", I);
	 I = trapIntegrate(x1, x2, dx, f1);
	printf("функция 1: метод трапеций: %f\n", I);
	 I = rectIntegrate(x1, x2, dx, f2);
	printf("функция 2: метод прямоугольников: %f\n", I);
	 I = trapIntegrate(x1, x2, dx, f2);
	printf("функция 2: метод трапеций: %f\n", I);
}
