//Лабораторная работа №2
//Задание: Найти минимальный положительный корень уравнения
//методом деления пополам с точностью 10e-5

#include <iostream> // Библиотека ввода-вывода
#include <iomanip>	// Библиотека модификатора вывода
#include <cmath>	// Математическая библиотека

using namespace std;

long double func(long double x) {
	return pow(x-1, 2) - pow(M_E, x) / 2;
}

int main() {
	unsigned short epsilon; //Точность вида 1E-**
	long double x; //Аргумент
	long double a = -10, b = 10; //Границы начала поиска

	cout << "	Hello!" << endl << endl;
	cout << "Enter the accuracy of the last item:" << endl;
	cout << "	1E-"; cin >> epsilon;
	long double endEps = pow(10, -epsilon); //Преобразование введенной точности
	cout << endl;

	size_t i = 0; //Счетчик итераций
	x = (a + b) / 2; //Начальная итерация
	while (abs(func(x)) >= endEps){		//
		x = (a + b) / 2;				//
		if (func(a)*func(x) < 0)		//
			b = x;						// Цикл
		else							// поиска
			a = x;						//
		i++;							//
	}									//

	//Вывод результатов
	cout << "Amount of iterations = " << i << endl << endl;
	cout << setprecision(60) << "	X = " << a << endl;
	cout << "	Difference = " << setprecision(60) << 0 - func(a) << endl;
	cout << endl;
	return 0;
}
