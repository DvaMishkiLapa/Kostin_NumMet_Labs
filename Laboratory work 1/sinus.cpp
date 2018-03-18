//Лабораторная работа №1
//Задание: Рассчитать значение синуса в x с точностью 10e-5

#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

void adduct(long double* arg) {
	long double newpi = 2 * M_PI;
	if (*arg > 0)
		while ((*arg) >= newpi)
			*arg -= newpi;
	else
		while ((*arg) <= newpi)
			*arg += newpi;
}


long double sinx(long double x, long double epsilon) {
	long double n = x, sum = 0;
	int i = 1;
	do {
		sum += n;
		n *= -1 * x * x / ((2 * i) * (2 * i + 1));
		i++;
	} while (abs(n) > pow(10, -epsilon));
	return sum;
}


int main() {
	unsigned short epsilon;
	long double arg;

	cout << "Hello!" << endl;
	cout << "Enter the function argument" << endl;
	cout << "	sin "; cin >> arg;

	cout << "Use the reduction formulas? (More error of calculations)" << endl;
	cout << "	1) Yes" << endl;
	cout << "	2) No" << endl;
	int answer; cin >> answer;
	if (answer) adduct(&arg);

	cout << "Enter the accuracy of the last item:" << endl;
	cout << "	1E-"; cin >> epsilon;
	cout << endl;

	long double handSin = sinx(arg, epsilon);
	long double originalSin = sin(arg);
	cout << "Original sin(x) = " << setprecision(60) << originalSin << endl;
	cout << "Handmade sin(x) = " << setprecision(60) << handSin << endl;
	cout << endl << "Difference: " << setprecision(60) << abs(handSin - originalSin) << endl << endl;
	return 0;
}
