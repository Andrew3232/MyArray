#pragma once

template<class T>
class MyArray
{
private:
	T **Data;
	int CountRows, CountCols;
public:
	//methods
	int GetCountRows();
	int GetCountCols();
	T** GetData();
	int SetCountRows(int NewCountRows);
	int SetCountCols(int NewCountCols);
	int SetData(double** newData, int NewCountRows, int NewcountCols);
	int SetElement(int IndexRows, int IndexCols, T Value);
	double GetElement(int indexRows, int IndexCols);

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
	MyArray(MyArray& a);
	~MyArray();

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
	/*friend ostream& operator<<(ostream& stream, MyArray<T>& A) {

	}

	friend istream& operator>>(istream& stream, MyArray<T>& A) {

	}*/
};

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

