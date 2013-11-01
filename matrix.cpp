/* 
 * File:   matrix.cpp
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

#include "matrix.hpp"

using namespace std;

/*
 * Klasa macierzy - dwuwymiarowa
 *
 * Matrix create in default 3x3
 * 
 * Functions:
 *      - Set Data (Specific number, Random, String of data)
 *      - Change sign of matrix for opposite (example: -A)
 *      - Add (matrix)
 *      - Subtract (matrix)
 *      - Multiply (matrix by matrix, matrix by number)
 *      - Transpose ()
 *      - Inverse ()
 *      - Calculate determinant of the matrix
 *      - Calculate moda of the matrix
 */

/*
 * Constructors & Destructors
 */
// Default matrix 3x3 with random numbers
matrix::matrix(void)
:rows(3), cols(3)
{
    allocateArrays();
    setDataRandomNumbers();
}

// Create matrix with proper col and rows; filed by 0 default
matrix::matrix(int r, int c)
:rows(r), cols(c)
{
    allocateArrays();
    setData(0);
}

/*
 * Create matrix with data
 * 
 * Note!!! Always end with semicolon ;
 * Format: 1,3.5,-4;300,200,33;0,-2.5,2323.5;
 */
matrix::matrix(string inputData)
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

matrix::~matrix(void)
{
    for (int i=0; i<rows; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

/**
 * Functions
 */
// Private ---------------------------------------------------------------------
void matrix::allocateArrays()
{
    data = new double *[rows];
    for(int i=0; i<rows; ++i)
    {
        data[i] = new double[cols];
    }
}

void matrix::removeWhiteCharacters(string &str)
{
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
}



// Public ----------------------------------------------------------------------
int matrix::getRows()
{
    return rows;
}

int matrix::getCols()
{
    return cols;
}

bool matrix::isNumber(std::string s)
{
    return true;
}
/*
bool matrix::isInteger(const string &s)
{
    boost::regex integer("(\\+|-)?[[:digit:]]+");

    if( boost::regex_match(s, integer) )
        return true;
    else
        return false;
}
*/
void matrix::setData(double number)
{
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            data[i][j] = number;
        }
    }
}

void matrix::setData(string inputData)
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
    
    // check if number of data equal matrix cells
    if(cols*rows != vect.size())
        throw "Liczba pól w macierzy nie pokrywa się z ilością wprowadzonych danych"; 
    
    int r=0;
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            data[i][j] = vect[r];
            r++;
        }
    }
}

void matrix::setDataRandomNumbers()
{
    srand(time(NULL));
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            data[i][j] = (rand()%899 + 100);
        }
    }
}

matrix matrix::operator+(int number)
{
    matrix result(this->rows, this->cols);
    for(int i=0; i<result.rows; ++i)
    {
        for(int j=0; j<result.cols; ++j)
        {
            result.data[i][j] += number;
        }
    }
    return result;
}

matrix matrix::operator-()
{
    matrix result;
    for(int i=0; i<result.rows; ++i)
    {
        for(int j=0; j<result.cols; ++j)
        {
            result.data[i][j] = -data[i][j];
        }
    }
    return result;
}

matrix matrix::multiply(double)
{

}

matrix matrix::multiply(matrix)
{

}

matrix matrix::transpose(matrix)
{

}

double matrix::determinant(double)
{
    return 0;
}

void matrix::printSize()
{
    cout << rows << " x " << cols;
}

void matrix::print()
{
    cout << endl;
    for(int i=0; i<rows; i++)
    {
        cout << "\t| ";
        for(int j=0; j<cols; j++)
        {
            cout << "" << data[i][j] << " ";
        }
        // print Size of matrix on the end
        if(i==rows-1)
        {
            cout << "| ";
            printSize();
        }
        else
        {
            cout << "|" << endl;
        }

    }

}