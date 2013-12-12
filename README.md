# Least Squares Method

This very simple program was written in C++ to calculate method of least squares (regression analysis).
It's based on main matrix class to estimate line regresion of inputed data.

## IDE

This little project has been built with [NetBeans IDE 7.4](https://netbeans.org/).


## Matrix Class Api

Features:

  - Overwrite minor group of operators `()`, `=`, `+`, `+=`, `-`, `-=`, `<<`, `*`, `^`,
  - Add some specyfic function to the class Matrix like `transpose` or `determinant`,
  - Add some helper functions to glue all friend and build-in functions together, like:
    * isEvenNumber
    * isNegativeNumber
    * highestValue
    * isMatrixSizeEqual
    * etc ;)

What more TODO:

  - To improve creating objects, constructor can be overwritten in ex: A("1,2;3,4;5,6;") and it should create matrix A with dimension of 3x2 and filled cells with data. Some scratch of implementation is all ready and put in the comments in the class Matrix.

## Tests
Minor and simple tests of basic functions and Least Square Method are all ready written in main file.

## License

```
The MIT License (MIT)

Copyright (c) 2013 Maciej Sypień

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
