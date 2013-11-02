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
 *      - Add (Matrix)
 *      - Subtract (Matrix)
 *      - Multiply (Matrix by Matrix, Matrix by number)
 *      - Transpose ()
 *      - Inverse ()
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
// Private ---------------------------------------------------------------------
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



// Public ----------------------------------------------------------------------
int Matrix::getRows()
{
    return rows;
}

int Matrix::getCols()
{
    return cols;
}

//TODO
bool Matrix::isNumber(const string &s)
{
    return true;
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


Matrix Matrix::transpose(Matrix)
{

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
    for(int i=0; i<m.rows; i++)
    {
        for(int j=0; j<m.cols; j++)
            out << "" << m.data[i][j] << " ";
        out << endl;
    }
    return out;
}