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

        cout << "macierz X";
        X.print();
        cout << endl;

        cout << "macierz trzecia";
        Y.print();
        cout << endl;

        X.print();
        X.setData("14,45 ,3, 78,90,58,34,234,34");
        X.print();
        
        X.print();
        Y = X;
        Y.print();

    }
    catch (const char* msg) 
    {
        cerr << msg << endl;
    }
    return 0;

}