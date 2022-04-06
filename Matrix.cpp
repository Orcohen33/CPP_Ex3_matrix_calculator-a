#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include "Matrix.hpp"

using namespace std;

namespace zich
{
    // constructors
    Matrix::Matrix(vector<double> arr, int rows, int cols)
    {}
    Matrix::Matrix(int rows, int cols)
    {}
    Matrix::Matrix(const Matrix &other)
    {}

    // arithmetic operators overloading
    Matrix operator+(const Matrix &a)
    {return a;}
    Matrix operator+(const Matrix &a, const Matrix &b)
    {return a;}
    Matrix operator+(double a, const Matrix &b)
    {return b;}
    Matrix operator+(const Matrix &a, double b)
    {return a;}
    Matrix operator+=(Matrix &a, const Matrix &b)
    {return a;}
    Matrix operator+=(Matrix &a, double b)
    {return a;}
    Matrix operator-(const Matrix &a)
    {return a;}
    Matrix operator-(const Matrix &a, const Matrix &b)
    {return a;}
    Matrix operator-(double a, const Matrix &b)
    {return b;}
    Matrix operator-(const Matrix &a, double b)
    {return a;}
    Matrix operator-=(Matrix &a, const Matrix &b)
    {return a;}
    Matrix operator-=(Matrix &a, double b)
    {return a;}

    // Comparison operators
    bool operator==(const Matrix &a, const Matrix &b)
    {return true;}
    bool operator!=(const Matrix &a, const Matrix &b)
    {return true;}
    bool operator<(const Matrix &a, const Matrix &b)
    {return true;}
    bool operator>(const Matrix &a, const Matrix &b)
    {return true;}
    bool operator<=(const Matrix &a, const Matrix &b)
    {return true;}
    bool operator>=(const Matrix &a, const Matrix &b)
    {return true;}

    // increase\decrease methods
    Matrix &Matrix::operator++()
    {return *this;}
    Matrix Matrix::operator++(int)
    {return *this;}
    Matrix &Matrix::operator--()
    {return *this;}
    Matrix Matrix::operator--(int)
    {return *this;}

    // multiplication operators
    Matrix operator*(double scalar, const Matrix &a)
    {return a;}
    Matrix operator*(const Matrix &a, double scalar)
    {return a;}
    Matrix operator*(const Matrix &a, const Matrix &b)
    {return a;}
    Matrix operator*=(Matrix &a, double scalar)
    {return a;}
    Matrix operator*=(double scalar, Matrix &a)
    {return a;}
    Matrix operator*=(Matrix &a, const Matrix &b)
    {return a;}
    // cin & cout override methods
    ostream &operator<<(ostream &os, const Matrix &matrix)
    {return os;}
    istream &operator>>(istream &is, Matrix &matrix) { return is; }

    // distructure
    Matrix::~Matrix()
    {}
}
