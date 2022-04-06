#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        vector<double> arr;
        int rows;
        int cols;

    public:
        /**
         * @brief Construct a new Matrix object
         *
         * @param arr
         * @param rows
         * @param cols
         */
        Matrix(vector<double> arr, int rows, int cols); // constructor taking a vector and a matrix size
        Matrix(int rows, int cols);                     // constructor taking a matrix size
        Matrix(const Matrix &other);                    // copy constructor

        // Overriding arithmetic operators
        friend Matrix operator+(const Matrix &a);                  // unary plus
        friend Matrix operator+(const Matrix &a, double b);        // plus scalar
        friend Matrix operator+(double a, const Matrix &b);        // plus scalar
        friend Matrix operator+(const Matrix &a, const Matrix &b); // plus
        friend Matrix operator+=(Matrix &a, const Matrix &b);      // plus equals
        friend Matrix operator+=(Matrix &a, double b);             // plus equals scalar
        friend Matrix operator-(const Matrix &a);                  // unary minus
        friend Matrix operator-(const Matrix &a, double b);        // minus scalar
        friend Matrix operator-(double a, const Matrix &b);        // minus scalar
        friend Matrix operator-(const Matrix &a, const Matrix &b); // minus
        friend Matrix operator-=(Matrix &a, const Matrix &b);      // minus equals
        friend Matrix operator-=(Matrix &a, double b);             // minus equals scalar

        // Comparison operators
        friend bool operator==(const Matrix &a, const Matrix &b); // equality
        friend bool operator!=(const Matrix &a, const Matrix &b); // inequality
        friend bool operator>(const Matrix &a, const Matrix &b);  // greater than
        friend bool operator<(const Matrix &a, const Matrix &b);  // less than
        friend bool operator>=(const Matrix &a, const Matrix &b); // greater than or equal to
        friend bool operator<=(const Matrix &a, const Matrix &b); // less than or equal to

        // Overriding increase/decrease methods
        Matrix &operator++();   // prefix
        Matrix operator++(int); // postfix
        Matrix &operator--();   // prefix
        Matrix operator--(int); // postfix

        // Overriding multiplication operators
        friend Matrix operator*(double scalar, const Matrix &a);   // scalar multiplication
        friend Matrix operator*(const Matrix &a, double scalar);   // scalar multiplication
        friend Matrix operator*(const Matrix &a, const Matrix &b); // matrix multiplication
        friend Matrix operator*=(Matrix &a, const Matrix &b);      // matrix multiplication equals
        friend Matrix operator*=(Matrix &a, double scalar);        // scalar multiplication equals
        friend Matrix operator*=(Matrix &a, const Matrix &b);      // matrix multiplication equals
        // cin & cout override methods

        friend ostream &operator<<(ostream &os, const Matrix &matrix); // print
        friend istream &operator>>(istream &is, Matrix &matrix);       // read

        ~Matrix();
    };
}
