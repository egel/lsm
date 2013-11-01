/* 
 * File:   matrix.hpp
 * Author: maciek
 *
 * Created on 29 październik 2013, 17:16
 */

#ifndef MATRIX_HPP
#define	MATRIX_HPP

#include <iostream>
#include <string>

using namespace std;

class matrix
{
    //konstruktory i destruktory
    public:
        matrix(int rows, int cols);
        // TODO matrix(string inputData);
        matrix(const matrix &m);
        matrix();
        ~matrix(void);

    // zmienne
    private:
        int rows, cols;
        double **data;

    // deklaracje funkcji
    protected:
        void allocateArrays();
        void removeWhiteCharacters(string &str);

    public:
        int getRows();
        int getCols();
        
        // TODO
        bool isNumber(const string &str);
        // TODO bool isInteger(const string &str);
        // TODO bool isFloat(const string &str);

        void setData(double number);
        void setData(string inputData);
        void setDataRandomNumbers();
        
        matrix &operator=(const matrix &m);
        matrix operator+(double number);
        matrix operator-();
        matrix multiply(double);
        matrix multiply(matrix);
        matrix transpose(matrix);
        double determinant(double);
        
        void printSize();
        void print();
};

#endif	/* MATRIX_HPP */

