// Array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "MyArray.h"

using namespace std;

int main()
{
	MyArray<double> a1(1, 1), a2(3, 3);
	cin >> a2;
	//a2.SetData(a1.GetData(), 1, 1);
	cout << a2 << endl;


}

