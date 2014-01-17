# Least Squares Method

This very simple program was written in C++ to calculate method of least squares (regression analysis).
It's based on main matrix class to estimate line regresion of inputed data.


## IDE

This little project has been built with [NetBeans IDE 7.4](https://netbeans.org/).


## Matrix Class

Features:

  - Overwritten minor group of operators `()`, `=`, `+`, `+=`, `-`, `-=`, `<<`, `*`, `^`,
  - Added some specyfic functions to the class Matrix like `transpose` or `determinant`,
  - Added some helper functions to glue all friend and build-in functions together, like:
    * isEvenNumber
    * isNegativeNumber
    * highestValue
    * isMatrixSizeEqual
    * etc. ;)

What more TODO:

  - To improve creating objects, constructor can be overwritten in ex: A("1,2;3,4;5,6;") and it should create matrix A with dimension of 3x2 and filled cells with data. Some scratch of implementation is all ready and put in the comments in the class Matrix.


## Install

It's two way to install.

  - **Recommended**: Use [Git](http://git-scm.com/) and run `git clone git@github.com:egel/lsm.git` in terminal
  - Download all files in package and extract it.


## Tests
Minor and simple tests of basic functions and Least Square Method are all ready written in main file.


## Improvements
All improvements wide or minor are welcome :)


## License
The code is released under the [GNU General Public License 3](http://www.gnu.org/copyleft/gpl.html) - [Link to local license](https://github.com/egel/lsm/blob/master/LICENSE
).
