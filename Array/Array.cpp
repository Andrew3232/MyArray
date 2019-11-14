// Array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "MyArray.h"

using namespace std;

int main()
{
	MyArray<double> a1(3, 3), a2(3, 3), a3(1,1);
	cin >> a1;
	cin >> a2;

	double b = 5;
	cout << "a1 + a2\n" << *&(a1 + a2) << endl;
	cout << "a1 + b\n" << *&(a1 + b) << endl;
	cout << "a1 - b\n" << *&(b - a1) << endl;
	cout << "a2 * b\n" << *&(b * a2) << endl;
	cout << "a2 / b\n" << *&(a2 / b) << endl;
	cout << "a1 * a2\n" << *&(a1 * a2) << endl;
	cout << "a1\n" << a1 << endl;
	a3 = *&(a1 * a2);
	cout << "a2\n" << a2 << endl;
	cout << "a3\n" << a3 << endl;
	cout << (a1 == a3) << endl;


}

