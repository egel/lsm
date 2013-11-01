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
        matrix matrixOne;
        matrix matrixThree(2,6);
        matrix x(3,3);

        cout << "macierz pierwsza";
        matrixOne.print();
        cout << endl;

        cout << "macierz trzecia";
        matrixThree.print();
        cout << endl;

        matrixOne.print();
        matrixOne.setData("14,45 ,3, 78,90,58,34,234,34");
        matrixOne.print();
        
        x.print();
        x = x + 2;
        x.print();

    }
    catch (const char* msg) 
    {
        cerr << msg << endl;
    }
    return 0;

}