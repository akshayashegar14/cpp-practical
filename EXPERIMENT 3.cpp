
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:
    // Constructor
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    // Operator Overloading for Addition
    Matrix operator+(const Matrix &m) const
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }

        return result;
    }

    // Operator Overloading for Multiplication
    Matrix operator*(const Matrix &m) const
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }

        return result;
    }

    // Operator Overloading for []
    int* operator[](int index)
    {
        return data[index];
    }

    const int* operator[](int index) const
    {
        return data[index];
    }

    // Operator Overloading for <<
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            out << "| ";

            for (int j = 0; j < 2; j++)
            {
                out << setw(4) << m.data[i][j] << " ";
            }

            out << "|" << endl;
        }

        return out;
    }
};

int main()
{
    Matrix A(2, 4, 1, 3);
    Matrix B(6, 1, 5, 2);

    // Matrix Operations
    Matrix sum = A + B;
    Matrix product = A * B;

    // Unit Testing
    assert(sum[0][0] == 8);
    assert(sum[0][1] == 5);
    assert(sum[1][0] == 6);
    assert(sum[1][1] == 5);

    assert(product[0][0] == 32);
    assert(product[0][1] == 10);
    assert(product[1][0] == 21);
    assert(product[1][1] == 7);

    // Display Results
    cout << "\n==================================" << endl;
    cout << "       MATRIX OPERATIONS          " << endl;
    cout << "==================================" << endl;

    cout << "\nFirst Matrix (A):" << endl;
    cout << A;

    cout << "\nSecond Matrix (B):" << endl;
    cout << B;

    cout << "\nMatrix Addition (A + B):" << endl;
    cout << sum;

    cout << "\nMatrix Multiplication (A * B):" << endl;
    cout << product;

    cout << "\n==================================" << endl;
    cout << "   ALL UNIT TESTS PASSED!" << endl;
    cout << "   MATRIX OPERATIONS COMPLETED" << endl;
    cout << "==================================" << endl;

    return 0;
}
