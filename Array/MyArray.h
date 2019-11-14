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
		CountCols = a.GetCountCols();
		for (int i = 0; i < CountRows; i++)
			for (int j = 0; j < CountCols; j++)
				Data[i][j] = a.GetElement(i, j);
	};
	~MyArray() {};

	//operators
	friend MyArray operator+(MyArray& a, MyArray& b) {
		if (a.GetCountRows() == b.GetCountRows() && a.GetCountCols() == b.GetCountCols()) {
			T temp;
			MyArray<T> c(a.GetCountRows(), b.GetCountCols());
			for (int i = 0; i < c.GetCountRows(); i++) {
				for (int j = 0; j < c.GetCountCols(); j++) {
					temp = a.GetElement(i, j) + b.GetElement(i, j);
					c.SetElement(i, j, temp);
				}
			}
			return c;
		}
		else
			exception;
	}; 
	friend MyArray operator+(MyArray& a, T b){
		T temp;
		MyArray<T> c(a.GetCountRows(), a.GetCountCols());
		for (int i = 0; i < a.GetCountRows(); i++) {
			for (int j = 0; j < a.GetCountCols(); j++) {
				temp = a.GetElement(i, j) + b;
				c.SetElement(i, j, temp);
			}
		}
		return c;
	};
	friend MyArray operator+(T b, MyArray& a) {
		T temp;
		MyArray<T> c(a.GetCountRows(), a.GetCountCols());
		for (int i = 0; i < a.GetCountRows(); i++) {
			for (int j = 0; j < a.GetCountCols(); j++) {
				temp = a.GetElement(i, j) + b;
				c.SetElement(i, j, temp);
			}
		}
		return c;
	};
	friend MyArray operator-(MyArray& a, MyArray& b) {
		if (a.GetCountRows() == b.GetCountRows() && a.GetCountCols() == b.GetCountCols()) {
			T temp;
			MyArray<T> c(a.GetCountRows(), b.GetCountCols());
			for (int i = 0; i < c.GetCountRows(); i++) {
				for (int j = 0; j < c.GetCountCols(); j++) {
					temp = a.GetElement(i, j) - b.GetElement(i, j);
					c.SetElement(i, j, temp);
				}
			}
			return c;
		}
		else
			exception;
	};
	friend MyArray operator-(MyArray& a, T b) {
		T temp;
		MyArray<T> c(a.GetCountRows(), a.GetCountCols());
		for (int i = 0; i < a.GetCountRows(); i++) {
			for (int j = 0; j < a.GetCountCols(); j++) {
				temp = a.GetElement(i, j) - b;
				c.SetElement(i, j, temp);
			}
		}
		return c;
	};
	friend MyArray operator-(T b, MyArray& a) {
		T temp;
		MyArray<T> c(a.GetCountRows(), a.GetCountCols());
		for (int i = 0; i < a.GetCountRows(); i++) {
			for (int j = 0; j < a.GetCountCols(); j++) {
				temp = a.GetElement(i, j) - b;
				c.SetElement(i, j, temp);
			}
		}
		return c;
	};

	friend MyArray operator*(MyArray& a, MyArray& b) {
		if (a.GetCountCols() != b.GetCountRows()) {
			cout << ("ColsA != RowsB") << endl;
			exception;
			exit(0);
		}
		else {
			T temp;
			MyArray<T> c(a.GetCountRows(), b.GetCountCols());
			for(int k = 0; k < b.GetCountCols(); k++)
			for (int i = 0; i < a.GetCountRows(); i++) {
				temp = 0;
				for (int j = 0; j < b.GetCountCols(); j++) {
					temp += a.GetElement(k, j) * b.GetElement(j,i);					
				}
				c.SetElement(k, i, temp);
			}
			return c;
		}
	};
	friend MyArray operator*(MyArray& a, T b) {
		T temp;
		MyArray<T> c(a.GetCountRows(), a.GetCountCols());
		for (int i = 0; i < a.GetCountRows(); i++) {
			for (int j = 0; j < a.GetCountCols(); j++) {
				temp = a.GetElement(i, j) * b;
				c.SetElement(i, j, temp);
			}
		}
		return c;
	};
	friend MyArray operator*(T b, MyArray& a) {
		T temp;
		MyArray<T> c(a.GetCountRows(), a.GetCountCols());
		for (int i = 0; i < a.GetCountRows(); i++) {
			for (int j = 0; j < a.GetCountCols(); j++) {
				temp = a.GetElement(i, j) * b;
				c.SetElement(i, j, temp);
			}
		}
		return c;
	};
	friend MyArray operator/(MyArray& a, T b) {
		T temp;
		MyArray<T> c(a.GetCountRows(), a.GetCountCols());
		for (int i = 0; i < a.GetCountRows(); i++) {
			for (int j = 0; j < a.GetCountCols(); j++) {
				temp = a.GetElement(i, j) / b;
				c.SetElement(i, j, temp);
			}
		}
		return c;
	};

	void operator=(MyArray& a) {
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
		CountCols = a.GetCountCols();
		for (int i = 0; i < CountRows; i++)
			for (int j = 0; j < CountCols; j++)
				Data[i][j] = a.GetElement(i, j);
	};
	bool operator==(MyArray& a) {
		if (this->GetCountRows()!= a.GetCountRows() || this->GetCountCols() != a.GetCountCols())
			exit(0);
		for (int i = 0; i < a.GetCountRows(); i++) {
			for (int j = 0; j < a.GetCountCols(); j++) {
				if (GetElement(i, j) != a.GetElement(i, j))
					return false;
			}
		}
		return true;
	};

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
		cout << "Enter Array:\n";
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