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

        cout << "Macierz X" << endl;
        X.print();
        cout << endl;

        cout << "Macierz Y" << endl;
        Y.print();
        cout << endl;
        
        cout << "macierz X przed wprowadzeniem danych" << endl;
        X.print();
        X.setData("14,45 ,3, 78,90,58,34,234,34");
        cout <<endl<< "po wprowadzeniu danych" <<endl;
        X.print();
        
        cout << endl << "macierz X" << endl;
        X.print();
        cout << endl << "...przypisanie y = x..." << endl;
        Y = X;
        cout << "macierz Y" << endl;
        Y.print();
        
        cout << endl << "Dodanie Y do X -> X+=Y" << endl;
        X+=Y;
        X.print();
        cout << endl << "Odjęcie Y do X -> X-=Y" << endl;
        X-=Y;
        cout << X << endl;
        
        
        
    }
    catch (const char* msg) 
    {
        cerr << msg << endl;
    }
    return 0;

}