// Лабораторная работа №4
// Задание: Вычислить интеграл
// методом Симпсона с точностью 10e-5.

#include <iostream> //Библиотека ввода-вывода.
#include <iomanip>	//Библиотека модификатора вывода.
#include <cmath>	//Математическая библиотека.

using namespace std;

//Подынтегральная функция
long double func(long double x) {
	//return x * sqrt(x) * exp(-x);
	return sqrt(x) * sin(x);
}


int main() {
	//Нижний и верхний пределы интегрирования (a, b).
	long double a = 0;
	long double b = 1;

	//Погрешность(eps).
	long double eps;
	cout << "Enter the accuracy:" << endl;
	cout << "	1E-"; cin >> eps;
	eps = powl(10, -eps);

	//i_first - предыдущее вычисленное значение интеграла, i_next - новое, с большим N.
	long double i_first = eps + 1, i_next = 0;

	//step - кол-во выполнения цикла, N - кол-во разбиений.
	size_t step = 0, N = 2;
	for (; fabs(i_next - i_first) > eps; N *= 2, step++) {
		long double h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b - a) / (2 * N); //Шаг интегрирования.
		for (size_t i = 1; i <= 2 * N - 1; i += 2) {
			sum4 += func(a + h * i); //Значения с нечётными индексами, которые нужно умножить на 4.
			sum2 += func(a + h * (i + 1)); //Значения с чётными индексами, которые нужно умножить на 2.
		}
		sum = func(a) + 4 * sum4 + 2 * sum2 - func(b); //Отнимаем значение func(b), так как ранее прибавили его дважды. 
		i_first = i_next;
		i_next = (h / 3) * sum;
	}

	cout << "Amount of iterations = " << step << endl;
	cout << "Amount of segments = " << N << endl << endl;
	cout << "The integral = " << setprecision(6) << i_next << endl << endl;

	cout << "Full result = " << setprecision(60) << i_next << endl;
	return 0;
}