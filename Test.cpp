#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <random>
#include <stdexcept>
#include "doctest.h"
#include "Matrix.hpp"
using namespace std;
using namespace zich;

/**********************************************************************************************************
 *                                          UTILITIES
 * *******************************************************************************************************/
const int NUM_OF_TESTS = 100;

vector<double> randMat(int rows, int cols)
{
    vector<double> arr = vector<double>((size_t)(rows * cols), 0);
    for (size_t i = 0; i < rows * cols; i++)
    {
        arr[i] = rand() % 10 - 5;
    }
    return arr;
}

/**********************************************************************************************************
 *                                       CONSTRUCTOR
 * *******************************************************************************************************/
TEST_CASE("Constructor")
{
    SUBCASE("Zero row")
    {
        int row = 0;
        int col = 3;
        vector<double> arr = vector<double>((size_t)(row * col), 0);
        CHECK_THROWS(Matrix mat(arr, row, col));
    }
    SUBCASE("Zero col")
    {
        int row = 3;
        int col = 0;
        vector<double> arr = vector<double>((size_t)(row * col), 0);
        CHECK_THROWS(Matrix mat(arr, row, col));
    }
    SUBCASE("Negative row or col")
    {
        int rowA = -3, rowB = 3;
        int colA = 3, colB = -3;
        vector<double> arrA = vector<double>((size_t)(rowA * colA), 0);
        CHECK_THROWS(Matrix matA(arrA, rowA, colA));
        CHECK_THROWS(Matrix matB(arrA, rowB, colB));
    }
}

/**********************************************************************************************************
 *                                       ARITHMETIC OPERATORS
 * *******************************************************************************************************/

TEST_CASE("Arithmetic operators")
{
    int rowsA, rowsB, colsA, colsB;
    SUBCASE("Unary plus")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            Matrix b(+a);
            CHECK(a == b);
        }
    }
    SUBCASE("Plus")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(a + b);
            }
            else
            {
                Matrix c(a + b);
                CHECK(c == a + b);
            }
        }
    }
    SUBCASE("Plus scalar")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            double b = rand() % 10 - 5;
            Matrix c(a + b);
            CHECK(c == a + b);
        }
    }
    SUBCASE("Plus equals")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(a += b);
            }
            else
            {
                Matrix c(a);
                c += b;
                CHECK(c == a + b);
            }
        }
    }
    SUBCASE("Unary minus")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            Matrix b = -a;
            CHECK(a == -1 * b);
        }
    }
    SUBCASE("Minus")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(a - b);
            }
            else
            {
                Matrix c = a - b;
                CHECK(c == a - b);
            }
        }
    }
    SUBCASE("Minus scalar")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            double b = rand() % 10 - 5;
            Matrix c = a - b;
            CHECK(c == a - b);
        }
    }
    SUBCASE("Minus equals")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(a -= b);
            }
            else
            {
                Matrix c = a;
                c -= b;
                CHECK(c == a - b);
            }
        }
    }
}

/**********************************************************************************************************
 *                                       COMPARISON OPERATORS
 * *******************************************************************************************************/
TEST_CASE("Comparison operators")
{
    int rowsA, rowsB, colsA, colsB;
    bool ans = true;
    SUBCASE("Equals")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(ans = a == b);
            }
            else
            {
                ans = a == b;
                CHECK(ans == (a == b));
            }
        }
    }
    SUBCASE("Not equal")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(ans = a != b);
            }
            else
            {
                ans = a != b;
                CHECK(ans == (a != b));
            }
        }
    }
    SUBCASE("Less than")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(ans = a < b);
            }
            else
            {
                ans = a < b;
                CHECK(ans == (a < b));
            }
        }
    }
    SUBCASE("Less than or equal")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(ans = a <= b);
            }
            else
            {
                ans = a <= b;
                CHECK(ans == (a <= b));
            }
        }
    }
    SUBCASE("Greater than")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(ans = a > b);
            }
            else
            {
                ans = a > b;
                CHECK(ans == (a > b));
            }
        }
    }
    SUBCASE("Greater than or equal")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (rowsA != rowsB || colsA != colsB)
            {
                CHECK_THROWS(ans = a >= b);
            }
            else
            {
                ans = a >= b;
                CHECK(ans == (a >= b));
            }
        }
    }
}
/**********************************************************************************************************
 *                                        INCREASE\DECREASE
 * *******************************************************************************************************/
TEST_CASE("Increase || decrease operators")
{
    int rowsA, rowsB, colsA, colsB;
    SUBCASE("Prefix increase")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            Matrix b(a);
            ++a;
            CHECK((1 + b) == a);
        }
    }
    SUBCASE("Postfix increase")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            Matrix b(a);
            a++;
            CHECK((b + 1) == a);
        }
    }
    SUBCASE("Prefix decrease")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            Matrix b(a);
            --a;
            CHECK((b - 1) == a);
        }
    }
    SUBCASE("Postfix decrease")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            Matrix b(a);
            a--;
            CHECK((b - 1) == a);
        }
    }
}
/**********************************************************************************************************
 *                                         MULTIPLICATION
 * *******************************************************************************************************/
TEST_CASE("Multiplication")
{
    int rowsA, rowsB, colsA, colsB;
    SUBCASE("Multiplication by matrix")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            rowsB = rand() % 5 + 1;
            colsB = rand() % 5 + 1;
            Matrix b(randMat(rowsB, colsB), rowsB, colsB);
            if (colsA != rowsB)
            {
                CHECK_THROWS(a * b);
            }
            else
            {
                Matrix ans(a * b);
                CHECK(ans == (a * b));
            }
        }
    }
    SUBCASE("Multiplication by scalar")
    {
        for (int i = 0; i < NUM_OF_TESTS; i++)
        {
            rowsA = rand() % 5 + 1;
            colsA = rand() % 5 + 1;
            Matrix a(randMat(rowsA, colsA), rowsA, colsA);
            int scalar = rand() % 5 + 1;
            Matrix b(a);
            Matrix ans(a * scalar);
            Matrix ans2(scalar * a);
            a *= scalar;
            CHECK(ans == (b * scalar));
            CHECK(ans2 == (scalar * b));
            CHECK(a == ans);
            CHECK_NOTHROW(a * scalar);
        }
    }
}
/**********************************************************************************************************
 *                                              COUT
 * *******************************************************************************************************/
TEST_CASE("Cout")
{
    int rowsA, rowsB, colsA, colsB;
    for (int j = 0; j < 15; j++)
    {
        rowsA = rand() % 5 + 1;
        colsA = rand() % 5 + 1;
        vector<double> arr(size_t(rowsA * colsA), 0);
        for (size_t i = 0; i < rowsA * colsA; i++)
        {
            arr[i] = rand() % 5 + 1;
        }
        Matrix a(arr, rowsA, colsA);
        stringstream ss;
        ss << a;
        for (int i = 0; i < rowsA; i++)
        {
            string s;
            getline(ss, s);
            for (size_t i = 0; i < colsA * 2 + 1; i += 2)
            {
                if (s.at(i) == '[')
                {
                    CHECK(s.at(i) == '[');
                }
                else if (s.at(i) == ' ')
                {
                    CHECK(s.at(i) == ' ');
                }
                else if (s.at(i) == ']')
                {
                    CHECK(s.at(i) == ']');
                }
            }
        }
    }
}
