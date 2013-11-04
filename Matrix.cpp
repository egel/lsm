/* 
 * File:   Matrix.cpp
 * Author: maciek
 * 
 * Created on 29 październik 2013, 17:16
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <boost/regex.hpp>

#include "Matrix.hpp"

using namespace std;

/*
 * Klasa macierzy - dwuwymiarowa
 *
 * Matrix create in default 3x3
 * 
 * Functions:
 *      - Set Data (Specific number, Random, String of data)
 *      - Change sign of Matrix for opposite (example: -A)
 *      - Add (a+b, a+=b)
 *      - Subtract (ex: a-b, a-=b)
 *      - Multiply (ex: a*b, 3*a, a*2.563)
 *      - Power (ex: a^6, a^-1, a^0, a^2+6,)
 *      - Transpose ()
 *      - Inverse (ex: a^-1)
 *      - Calculate determinant of the Matrix
 *      - Calculate moda of the Matrix
 */

/*
 * Constructors & Destructors
 */

/* TODO !!!!!!!!!!!!!!!!!!!!!!!!!!
 * Create Matrix with data
 * 
 * Note!!! Always end with semicolon ;
 * Format: 1,3.5,-4;300,200,33;0,-2.5,2323.5;
 */
/*
Matrix::Matrix(string inputData)
{
    int comaCounter=0, semicolonCounter=0;
    
    removeWhiteCharacters(inputData);
    vector<double> vect;
    
    stringstream ss(inputData);

    int i;
    while(ss>>i)
    {
        vect.push_back(i);
        if(ss.peek() == ';')
            ss.ignore();
    }
    
    allocateArrays();
    setData(1);
}
*/

// Matrix fix col and rows filed with zeros default
Matrix::Matrix(int r, int c)
:rows(r), cols(c)
{
    allocateArrays();
    setData(0);
}

// Default Matrix 3x3 filled with zeros default
Matrix::Matrix(void)
:rows(3), cols(3)
{
    allocateArrays();
    setData(0);
}

Matrix::Matrix(const Matrix &m)
:rows(m.rows), cols(m.cols)
{
    allocateArrays();
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            data[i][j] = m.data[i][j];
        }
    }
}

Matrix::~Matrix(void)
{
    for (int i=0; i<rows; i++) {
        delete [] data[i];
    }
    delete [] data;
}

/**
 * Functions
 */
// Public ----------------------------------------------------------------------
//TODO
bool Matrix::isNumber(const string &s)
{
    return true;
}

/*
 * Return value of the last element with the highest value
 */
double Matrix::highestValue()
{
    double result = data[0][0];
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            if(result <= data[i][j])
                result = data[i][j];
        }
    }
    return result;
}

/*
 * Return bool if size of matrices are equal 
 */
bool isMatrixSizeEqual(const Matrix &m, const Matrix &n)
{
    if(m.rows == n.rows && m.cols == n.cols)
        return true;
    return false;
}

/*
 * Return bool if Columns of matrix 1 equal Rows of matrix 2
 */
bool isColsMatrix1EqualRowsMatrix2(const Matrix m, const Matrix n)
{
    if (m.cols == n.rows)
        return true;
    return false;
}

/*
 * Return bool if matrix is square
 */
bool isMatrixSquare(const Matrix &m)
{
    if (m.rows == m.cols)
        return true;
    return false;
}

/*
bool Matrix::isInteger(const string &s)s
{
    boost::regex integer("(\\+|-)?[[:digit:]]+");

    if( boost::regex_match(s, integer) )
        return true;
    else
        return false;
}
*/
void Matrix::setData(double number)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            data[i][j] = number;
        }
    }
}

//TODO
void Matrix::setData(string inputData)
{
    // a11, a12, a13; a21, a22, a23; a31, a32, a33;
    // ? sprawdzenie czy wartości sa liczbami
    // ! sprawdzenie czy ilość wartości się zgadzą (wiersze i kolumny)

    // usunięcie białych znaków
    removeWhiteCharacters(inputData);

    vector<int> vect;
    stringstream ss(inputData);
    
    int i;
    while(ss>>i)
    {
        vect.push_back(i);
        if(ss.peek() == ',')
            ss.ignore();
    }
    
    // check if number of data equal Matrix cells
    if(cols*rows != vect.size())
        throw "The number of fields in the matrix does not coincide with the amount of input data"; 
    
    int r=0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            data[i][j] = vect[r];
            r++;
        }
    }
}

void Matrix::setDataRandomNumbers()
{
    srand(time(NULL));
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            data[i][j] = (rand()%899 + 100);
        }
    }
}

Matrix &Matrix::operator=(const Matrix &m)
{
    // avoid self assignment
    if(this == &m)
    {
        return *this;
    }
    else
    {
        this-> ~Matrix();
        rows = m.rows; 
        cols = m.cols;
        allocateArrays();
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                data[i][j] = m.data[i][j];
            }
        }
        return *this;
    }
}

Matrix &Matrix::operator+=(const Matrix &m)
{
    // x+=y <=> x=x+y
    Matrix temp(*this); // copy constructor
    if(isMatrixSizeEqual(temp, m) == false)
        throw "Size of matrices are not equal";
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            data[i][j] += m.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &m)
{
    Matrix temp(*this); // use copy constructor
    return (temp+=m);
}

Matrix &Matrix::operator-=(const Matrix &m)
{
    // x-=y <=> x=x-y
    Matrix temp(*this); 
    if (isMatrixSizeEqual(temp, m) == false)
        throw "Size of matrices are not equal";
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            data[i][j] -= m.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &m)
{
    Matrix temp(*this);
    return (temp-=m);
}


Matrix Matrix::transpose()
{
    Matrix temp(this->cols, this->rows);
    for(int i=0; i<temp.rows; i++)
        for(int j=0; j<temp.cols; j++)
            temp.data[i][j] = this->data[j][i];
    return temp;
}

double Matrix::determinant(double)
{
    return 0;
}

void Matrix::printSize()
{
    cout << rows << " x " << cols;
}

void Matrix::print()
{
    for(int i=0; i<rows; i++)
    {
        cout << "\t| ";
        for(int j=0; j<cols; j++)
        {
            cout << "" << data[i][j] << " ";
        }
        // print Size of Matrix on the end
        if(i==rows-1)
        {
            cout << "| ";
            printSize();
            cout << endl;
        }
        else
        {
            cout << "|" << endl;
        }
    }
}

ostream &operator<<(ostream &out, const Matrix &m)
{   
    out << endl;
    for(int i=0; i<m.rows; i++)
    {
        out << "| ";
        for(int j=0; j<m.cols; j++)
            out << "" << m.data[i][j] << " ";
        out << "|" << endl;
    }
    return out;
}

Matrix operator*(const Matrix &m, const Matrix &n)
{
    if(m.cols != n.rows)
        throw "Column of matrix one not equal rows of matrix two";
    Matrix result(m.rows, n.cols);
    for (int i=0; i<result.rows; i++)
        for (int j=0; j<result.cols; j++)
            for (int k=0; k<m.cols; k++)
                result.data[i][j] += m.data[i][k] * n.data[k][j];
    return result;
}

Matrix operator*(double number, const Matrix &m)
{
    Matrix temp(m.rows, m.cols);
    for (int i=0; i<temp.rows; i++)
        for (int j=0; j<temp.cols; j++)
            temp.data[i][j] = number * m.data[i][j];
    return temp;
}

Matrix operator*(const Matrix &m, double number)
{
    return m * number;
}

Matrix operator^(const Matrix &m, long number)
{
    if(isMatrixSquare(m) == false)
        throw "Matrix is not sqaure";
        
    Matrix temp(m);
    if (number<-1)
    {
        throw "Can not to raise matrices to the power of negative numbers";
    }
    else if (number == -1)
    {
        
    }
    else if (number == 0)
    {
        for (int i=0; i<temp.rows; i++)
            for (int j=0; j<temp.cols; j++)
                if(i == j)
                    temp.data[i][j] = 1;
                else
                    temp.data[i][j] = 0;
        return temp;
    }
    else 
    {
        for (int q=1; q<number; q++)
            for (int i=0; i<temp.rows; i++)
                for (int j=0; j<temp.cols; j++)
                    temp.data[i][j] = temp.data[i][j] * m.data[i][j];
        return temp;
    }
}


// Protected -------------------------------------------------------------------
void Matrix::allocateArrays()
{
    data = new double *[rows];
    for(int i=0; i<rows; i++)
    {
        data[i] = new double[cols];
    }
}

void Matrix::removeWhiteCharacters(string &str)
{
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
}


// Private ---------------------------------------------------------------------
