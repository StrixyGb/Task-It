#include  <iostream>
using namespace std;
class Matrix {
private:
	int rows;
	int cols;
	int** data;
	void deleteMatrix() {
		for (int i = 0; i < rows; i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}
public:
	Matrix(int r, int c) : rows(r), cols(c) {
		data = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new int[cols];
		}
	}
	Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
		data = new int* [rows]; for (int i = 0; i < rows; i++)
		{
			data[i] = new int[cols];
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
	}
	void setelement(int r, int c, int value);
	int getlement(int r, int c) const;
	void print();
	~Matrix() {
		deleteMatrix();
	}
	Matrix& operator=(const Matrix& other) {
		if (this !=&other)
		{
			deleteMatrix();
		}

		rows = other.rows;
		cols = other.cols;

		data = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new int[cols];
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
		return *this;
	}
};
//Вирішив піти розкритим варіантом і функції проголосити в класі
//І заповнити їх поза класом)

void Matrix::setelement(int r, int c, int value) {
	if (r >= 0 && r < rows && c >= 0 && c < cols) {
		data[r][c] = value;
	}
}
int Matrix::getlement(int r, int c)const {
	if (r >= 0 && r < rows && c >= 0 && c < cols)
	{
		cout << data[r][c] << " ";
	}
	return 0;
}
void Matrix::print() {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << data[i][j] << " ";
		}
	}
}
void main() {
	Matrix matrix(3, 3);
	matrix.setelement(0, 0, 1);
	matrix.setelement(0, 1, 2);
	matrix.setelement(0, 2, 3);
	matrix.setelement(1, 0, 4);
	matrix.setelement(1, 1, 5);
	matrix.setelement(1, 2, 6);
	matrix.setelement(2, 0, 7);
	matrix.setelement(2, 1, 8);
	matrix.setelement(2, 2, 9);

	cout << "Matrix : " << endl;
	matrix.print();

	Matrix matrix2(3,3);
	matrix2 = matrix;
	cout << "\n\n\nPrinting Matrix2 copied from originally Matrix: " << endl;
	matrix2.print();
	matrix2.setelement(0, 0, 10);
	cout << "\n\n\nMatrix2 after updating by setting a new element; " << endl;
	matrix2.print();

	cout << "\n\n\nOriginal matrix without ay changing after changing matrix2 an alement: " << endl;
	matrix.print();

}