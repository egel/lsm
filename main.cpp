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

#include "matrix.hpp"

using namespace std;

int main()
{
    try
    {
        matrix X;
        matrix Y(2,6);

        cout << "macierz X" << endl;
        X.print();
        cout << endl;

        cout << "macierz Y" << endl;
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

    }
    catch (const char* msg) 
    {
        cerr << msg << endl;
    }
    return 0;

}