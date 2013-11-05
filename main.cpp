/* 
 * File:   main.cpp
 * Author: maciek
 *
 * Created on 29 październik 2013, 17:15
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>

#include "Matrix.hpp"

using namespace std;

int main()
{
    try
    {
        Matrix X, Y(2,6);

        cout << "Macierz X" << X << endl;
        
        cout << "Macierz Y" << Y << endl;
        
        cout << "Macierz X przed wprowadzeniem danych" << X << endl;
        X.setData("14,45 , 3, 78,90,58,34,234,34");
        cout << "...po wprowadzeniu danych" << X << endl;
        
        cout << "Macierz X" << X;
        cout << "...przypisanie y = x" << endl;
        Y = X;
        cout << "Macierz Y" << Y << endl;
        
        cout << "Y macierz 3x3" << Y << endl;
        cout << "Pobranie elemenutu z tablicy Y(0,0) = " << Y(0,0) << endl;
        cout << "Pobranie elemenutu z tablicy Y(2,2) = " << Y(2,2) << endl;
        
        cout << endl << "Dodanie macierzy Y do macierzy X -> X+=Y" << endl;
        X+=Y;
        cout << X << endl;
        cout << "Odjęcie macierzy Y od macierzy X -> X-=Y" << endl;
        X-=Y;
        cout << X << endl;
        
        cout << "Najwyższa wartość macierzy X to: " << X.highestValue() << endl;
        
        cout << endl << "Utworzenie macierzy A i B" << endl;
        Matrix a(3,2), b(2,3);
        a.setData("2,2,3,3,4,4");
        b.setData("2,3,4,2,3,4");
        cout << "Macierz a" << a << "Macierz b" << b << endl;
        cout << "Pomnożenie macierzy a * b i wyświetlenie macierzy c" << endl;
        Matrix c=a*b;
        cout << "Macierz c" << c;
        
        Matrix Z(3,3);
        cout << "Potęgowanie macierzy --------------------------------" << endl;
        Z.setData("1,2,3,1,2,3,1,2,3");
        cout << endl << "Potęgowanie macierzy Z^0" << endl;
        Z=Z^0;
        cout << Z << endl;
        Z.setData("1,2,3,1,2,3,1,2,3");
        cout << "Potęgowanie macierzy Z^1" << endl;
        Z=Z^1;
        cout << Z << endl;
        Z.setData("1,2,3,1,2,3,1,2,3");
        cout << "Potęgowanie macierzy Z^2" << endl;
        Z=Z^2;
        cout << Z << endl;
        Z.setData("1,2,3,1,2,3,1,2,3");
        cout << "Potęgowanie macierzy Z^3" << endl;
        Z=Z^3;
        cout << Z << endl;
        
        cout << "Transponowanie macierzy b" << endl;
        b = b.transpose();
        cout << b <<endl;
        
    }
    catch (const char* msg) 
    {
        cerr << msg << endl;
    }
    return 0;

}