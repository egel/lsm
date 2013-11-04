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

    public:
        // TODO
        bool isNumber(const string &str);
        // TODO bool isInteger(const string &str);
        // TODO bool isFloat(const string &str);
        double highestValue();
        friend bool isMatrixSizeEqual(const Matrix &m, const Matrix &n);
        friend bool isColsMatrix1EqualRowsMatrix2
            (const Matrix m, const Matrix n);
        friend bool isMatrixSquare(const Matrix &m);

        void setData(double number);
        void setData(string inputData);
        void setDataRandomNumbers();
        
        Matrix &operator=(const Matrix &m);
        Matrix &operator+=(const Matrix &m);
        Matrix operator+(const Matrix &m);
        Matrix &operator-=(const Matrix &m);
        Matrix operator-(const Matrix &m);
        
        //TODO
        Matrix transpose(Matrix);
        double determinant(double);     
        
        void printSize();
        void print();
        
        // Friend functions
        friend ostream &operator<<
            (ostream &out, const Matrix &m);
        //TODO
        friend Matrix operator*(const Matrix &m, const Matrix &n);
        friend Matrix operator*(double, const Matrix &m);
        friend Matrix operator*(const Matrix &m, double);
        friend Matrix operator^(const Matrix &m, long);
        
    // deklaracje funkcji
    protected:
        void allocateArrays();
        void removeWhiteCharacters(string &str);
        
    private:
        
        
};
#endif	/* MATRIX_HPP */

