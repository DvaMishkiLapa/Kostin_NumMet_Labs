//������������ ������ �2
//�������: ����� ����������� ������������� ������ ���������
//������� ������� ������� � ��������� 10e-5

#include <iostream> // ���������� �����-������
#include <iomanip>	// ���������� ������������ ������
#include <cmath>	// �������������� ����������

using namespace std;

long double func(long double x) {
	return pow(x-1, 2) - pow(M_E, x) / 2;
}

int main() {
	unsigned short epsilon; //�������� ���� 1E-**
	long double x; //��������
	long double a = -10, b = 10; //������� ������ ������

	cout << "	Hello!" << endl << endl;
	cout << "Enter the accuracy of the last item:" << endl;
	cout << "	1E-"; cin >> epsilon;
	long double endEps = pow(10, -epsilon); //�������������� ��������� ��������
	cout << endl;

	size_t i = 0; //������� ��������
	x = (a + b) / 2; //��������� ��������
	while (abs(func(x)) >= endEps){		//
		x = (a + b) / 2;				//
		if (func(a)*func(x) < 0)		//
			b = x;						// ����
		else							// ������
			a = x;						//
		i++;							//
	}									//

	//����� �����������
	cout << "Amount of iterations = " << i << endl << endl;
	cout << setprecision(60) << "	X = " << a << endl;
	cout << "	Difference = " << setprecision(60) << 0 - func(a) << endl;
	cout << endl;
	return 0;
}
