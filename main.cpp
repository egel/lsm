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
        cout << "----- Tworzenie Macierzy X, Y" << endl;
        Matrix X, Y(2,6);
        cout << "Macierz X" << X << endl;
        cout << "Macierz Y" << Y << endl;
        
        cout << "----- Macierz X przed wprowadzeniem danych" << X << endl;
        X.setData("14,45 , 3, 78,90,58,34,234,34");
        cout << "...po wprowadzeniu danych" << X << endl;
        
        cout << "----- Utworzenie macierzy W o rozmiarach 6 wierszy na 4 kolumn";
        Matrix W(6,4);
        cout << W;
        cout << "Liczba wierszy to: " << getNumberOfRows(W) << endl;
        cout << "Liczba kolumn to: " << getNumberOfColumns(W) << endl;
        
        cout << "----- Przypisanie macierzy y = x" << endl;
        cout << "Macierz X" << X;
        cout << "...przypisanie y = x..." << endl;
        Y = X;
        cout << "Macierz Y" << Y << endl;
        
        cout << "----- Y macierz 3x3" << Y << endl;
        cout << "Pobranie elemenutu z tablicy Y(1,1) = " << Y(1,1) << endl;
        cout << "Pobranie elemenutu z tablicy Y(3,3) = " << Y(3,3) << endl;
        
        cout << endl << "----- Dodanie macierzy Y do macierzy X -> X+=Y" << endl;
        X+=Y;
        cout << X << endl;
        cout << "----- Odjęcie macierzy Y od macierzy X -> X-=Y" << endl;
        X-=Y;
        cout << X << endl;
        
        cout << "----- Najwyższa wartość macierzy X to: " << X.highestValue() << endl;
        
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
        cout << b;
        
        cout << endl << "Usuwanie 3 kolumny z macierzy e" << endl;
        Matrix e(4,4);
        e.setData("1,2,3,6,5,4,3,7,2,1,2,3,4,4,0,0");
        cout << "Macierz e" << e;
        e = removeColumn(e,4);
        cout << e << endl;
        
        cout << endl << "Usuwanie 3 wiersza z macierzy e" << endl;
        cout << "Macierz e" << e;
        e = removeRow(e,4);
        cout << e << endl;
        
        cout << endl << "Wyznacznik macierzy f" << endl;
        Matrix f(1,1);
        f.setData("68");
        cout << "Macierz f" << f;
        cout << "Wyznacznik macierzy = " << determinant(f) << endl;
        
        cout << endl << "Wyznacznik macierzy g" << endl;
        Matrix g(2,2);
        g.setData("3,2,4,-2");
        cout << "Macierz g" << g;
        cout << "Wyznacznik macierzy = " << determinant(g) << endl;
        
        cout << endl << "Wyznacznik macierzy h" << endl;
        Matrix h(2,2);
        h.setData("-1000,+2000,-234,-23");
        cout << "Macierz h" << h;
        cout << "Wyznacznik macierzy = " << determinant(h) << endl;
        
        cout << endl << "Wyznacznik macierzy i" << endl;
        Matrix i(3,3);
        i.setData("1,2,3,6,5,4,3,7,2");
        cout << "Macierz i" << i;
        cout << "Wyznacznik macierzy = " << determinant(i) << endl;
        
        cout << endl << "Wyznacznik macierzy p" << endl;
        Matrix p(4,4);
        p.setData("1,2,3,6,5,4,3,7,2,1,2,3,4,4,0,0");
        cout << "Macierz p" << p;
        cout << determinant(p) << endl;
        
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    return 0;

}