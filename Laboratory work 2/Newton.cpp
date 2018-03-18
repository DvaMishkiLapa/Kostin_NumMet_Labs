//������������ ������ �2
//�������: ����� ����������� ������������� ������ ���������
//������� ������� � ��������� 10e-5

#include <iostream> // ���������� �����-������
#include <iomanip>	// ���������� ������������ ������
#include <cmath>	// �������������� ����������

using namespace std;

long double func(long double x) {
	return pow(x - 1, 2) - (pow(M_E, x) / 2);
}

//������ ����������� �� ��������� �������
long double derivFunc(long double x) {
	return 2*x - (pow(M_E, x) / 2) - 2;
}

//������ ����������� �� ��������� �������
long double twoDerivFunc(long double x) {
	return -(pow(M_E, x) / 2) + 2*x - 2;
}

int main() {
	unsigned short epsilon; //�������� ���� 1E-**
	long double x;
	cout << "Hello!" << endl;
	cout << "Set the initial approximation:" << endl;
	cout << "	x = "; cin >> x; //��������� �����������
	long double newX = x - func(x) / derivFunc(x);
	//�������, ������� ����������� ��� ������ ������
	if (func(x) * twoDerivFunc(x) < 0)
		cout << "A root can be obtained." << endl;
	else {
		cout << "A root can not be obtained." << endl;
		return 0;
	}
	cout << endl;

	cout << "Enter the accuracy of the last item:" << endl;
	cout << "	1E-"; cin >> epsilon;
	long double endEps = pow(10, -epsilon); //�������������� ��������� ��������
	cout << endl;

	size_t i = 0; //������� ��������
	while ((newX - x) > endEps) {			//	
		x = newX;							//
		newX = x - func(x) / derivFunc(x);	// ���� ������
		i++;								//
	}										//

	cout << "Amount of iterations = " << i << endl << endl;
	cout << setprecision(60) << "	X = " << x << endl;
	cout << "	Difference = " << setprecision(60) << 0 - func(x) << endl;
	cout << endl;
	return 0;
}
