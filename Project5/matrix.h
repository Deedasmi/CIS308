/**********************************************
* Name: Richad Petrie                         *
* Date: 12/2/2014                             *
* Assignment: Project 5: Matrices             *
***********************************************
* Mutiplies two matricies                     *
***********************************************/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public:
  Matrix(int, int);
  ~Matrix(void);
  void setElem(int, int, int);
  int getElem(int, int);
  Matrix* times(Matrix*);
  void print(void);
private:
  int rows;
  int cols;
  int **arr;
};

#endif
