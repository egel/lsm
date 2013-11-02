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
        X.setData("14,45 ,3, 78,90,58,34,234,34");
        cout << "...po wprowadzeniu danych" << X << endl;
        
        cout << "Macierz X" << X;
        cout << "...przypisanie y = x" << endl;
        Y = X;
        cout << "Macierz Y" << Y << endl;
        
        cout << "Dodanie macierzy Y do macierzy X -> X+=Y" << endl;
        X+=Y;
        cout << X << endl;
        cout << "Odjęcie macierzy Y od macierzy X -> X-=Y" << endl;
        X-=Y;
        cout << X << endl;
        
        
        
    }
    catch (const char* msg) 
    {
        cerr << msg << endl;
    }
    return 0;

}