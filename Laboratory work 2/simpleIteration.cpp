//Лабораторная работа №2
//Задание: Найти минимальный положительный корень уравнения
//методом простой итерации с точностью 10e-5

#include <iostream> // Библиотека ввода-вывода
#include <iomanip>	// Библиотека модификатора вывода
#include <cmath>	// Математическая библиотека

using namespace std;

long double func(long double x) {
	return pow(x - 1, 2) - (pow(M_E, x) / 2);
}

//Первая производная от начальной функции
long double derivFunc(long double x) {
	return 2 * x - (pow(M_E, x) / 2) - 2;
}

int main() {
	unsigned short epsilon; //Точность вида 1E-**
	long double x = 0; //Начальное приближение
	
	// -2.352585459037823679 - значение производной в точке 0.1
	long double lamb = 1 / -2.352585459037823679;
	
	cout << "Hello!" << endl;
	cout << "Enter the accuracy of the last item:" << endl;
	cout << "	1E-"; cin >> epsilon;
	long double endEps = pow(10, -epsilon); //Преобразование введенной точности
	cout << endl;

	long double newX = x - lamb * func(x);
	size_t i = 0; //Счетчик итераций
	while ((newX - x) > endEps) {	//
		x = newX;					//Цикл
		newX = x - lamb * func(x);	//поиска
		i++;						//	
	}									

	//cout  << endl << setprecision(60) << "	func'(0.3) = " << derivFunc(0.3) << endl;
	//cout << setprecision(60) << "	func'(0.1) = " << derivFunc(0.1) << endl << endl;

	cout << "	Amount of iterations = " << i << endl << endl;
	cout << setprecision(60) << "	X = " << x << endl;
	cout << "	Difference = " << setprecision(60) << 0 - func(x) << endl;
	cout << endl;
	return 0;
}
