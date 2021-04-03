// consoleIntegrate1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Версия: v2
#include <iostream>
#include <stdio.h>
#include <windows.h>
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
	HWND hwnd;
	char Title[1024];
	
	GetConsoleTitle(Title, 1024); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	HDC hdc = GetDC(hwnd);
	RECT rc;
	GetClientRect(hwnd, &rc);
	int iWidth = rc.right;
	int iHeight = rc.bottom;
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
	SetPixel(hdc, iWidth / 2, iHeight / 2, RGB(255, 0, 0)); //Установка пикселя
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
