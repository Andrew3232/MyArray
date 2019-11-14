#pragma once
#include <iostream>
#include <string>

using namespace std;
template<class T>
class MyArray
{
private:
	T **Data;
	int CountRows, CountCols;
public:
	//methods
	int GetCountRows() {
		return CountRows;
	}
	int GetCountCols() {
		return CountCols;
	}
	T GetElement(int indexRows, int IndexCols) {
		return Data[indexRows][IndexCols];
	};

	T** GetData() {
		return Data;
	};

	void SetCountRows(int NewCountRows) {
		CountRows = NewCountRows;
	};
	void SetCountCols(int NewCountCols) {
		CountCols = NewCountCols;
	};

	void SetData(T** newData, int NewCountRows, int NewcountCols) {
		for(int i = 0; i < CountRows; i++)
			delete Data[i];
		delete Data;
		Data = newData;		
	};

	void SetElement(int IndexRows, int IndexCols, T Value) {
		Data[IndexRows][IndexCols] = Value;
	};	

	//construct
	MyArray(int NewCountRows = 1, int NewCountCols = 1) {
		Data = new T * [NewCountRows];
		if (Data == nullptr)
			exit(0);
		for (int i = 0; i < NewCountRows; i++) {
			Data[i] = new T[NewCountCols];
			if (Data[i] == nullptr) {
				for (int j = 0; j < i; j++)
					delete Data[j];
				delete Data;
				exit(0);
			}
		}
		CountRows = NewCountRows;
		CountCols = NewCountCols;
	};
	MyArray(MyArray& a) {
		//cout << "In CopyConstructor";
		Data = new T * [a.GetCountRows()];
		if (Data == nullptr)
			exit(0);
		for (int i = 0; i < a.GetCountRows(); i++) {
			Data[i] = new T[a.GetCountCols()];
			if (Data[i] == nullptr) {
				for (int j = 0; j < i; j++)
					delete Data[j];
				delete Data;
				exit(0);
			}
		}
		CountRows = a.GetCountRows();
		CountCols = a.GetCountRows();
		for (int i = 0; i < CountRows; i++)
			for (int j = 0; j < CountCols; j++)
				Data[i][j] = a.GetElement(i, j);
	};
	~MyArray() {};

	//operators
	friend MyArray operator+(MyArray& a, MyArray& b);
	friend MyArray operator+(MyArray& a, T b);
	friend MyArray operator+(T b, MyArray& a);
	friend MyArray operator-(MyArray& a, MyArray& b);
	friend MyArray operator-(MyArray& a, T b);
	friend MyArray operator-(T b, MyArray& a);
	friend MyArray operator*(MyArray& a, MyArray& b);
	friend MyArray operator*(MyArray& a, T b);
	friend MyArray operator*(T b, MyArray& a);
	friend MyArray operator/(MyArray& a, T b);
	void operator=(MyArray& a);
	bool operator==(MyArray& a);

	//cin & cout
	friend ostream& operator<<(ostream& stream, MyArray<T>& A) {
		cout << "Arr[" << A.GetCountRows() << "][" << A.GetCountCols() << "] = " << endl;
		for (int i = 0; i < A.GetCountRows(); i++) {
			for (int j = 0; j < A.GetCountCols(); j++) {
				stream << A.GetElement(i, j) << " ";
			}
			stream << endl;
		}
		return stream;
	};	
	friend istream& operator>>(istream& stream, MyArray<T>& A) {
		cout << "Enter array:\n";
		T buffer;
		for (int i = 0; i < A.GetCountRows(); i++) {
			cout << "Row(" << i << ")\n";
			for (int j = 0; j < A.GetCountCols(); j++) {
				stream >> buffer;
				A.SetElement(i, j, buffer);
			}
		}
		return stream;
	};
};
/*
template <typename T>
MyArray<T>::MyArray(MyArray<T>& a) {
	//cout << "In CopyConstructor";
	Data = new T * [a.GetCountRows()];
	if (Data == nullptr)
		exit(0);
	for (int i = 0; i < a.GetCountRows(); i++) {
		Data[i] = new T[a.GetCountCols()];
		if (Data[i] == nullptr) {
			for (int j = 0; j < i; j++)
				delete Data[j];
			delete Data;
			exit(0);
		}
	}
	CountRows = a.GetCountRows();
	CountCols = a.GetCountRows();
	for (int i = 0; i < CountRows; i++)
		for (int j = 0; j < CountCols; j++)
			Data[i][j] = a.GetElement(i, j);
}
*/
