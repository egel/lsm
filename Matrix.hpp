/* 
 * File:   Matrix.hpp
 * Author: maciek
 *
 * Created on 29 październik 2013, 17:16
 */

#ifndef MATRIX_HPP
#define	MATRIX_HPP

#include <iostream>
#include <string>

using namespace std;

class Matrix
{
    //konstruktory i destruktory
    public:
        Matrix(int rows, int cols);
        // TODO Matrix(string inputData);
        Matrix(const Matrix &m);
        Matrix();
        ~Matrix(void);

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
        
        Matrix &operator=(const Matrix &m);
        Matrix &operator+=(const Matrix &m);
        Matrix operator+(const Matrix &m);
        Matrix operator-();
        Matrix multiply(double);
        Matrix multiply(Matrix);
        Matrix transpose(Matrix);
        double determinant(double);
        
        void printSize();
        void print();
};

#endif	/* MATRIX_HPP */

