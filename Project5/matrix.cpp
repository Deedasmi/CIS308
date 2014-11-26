/**********************************************
* Name: Richad Petrie                         *
* Date: 12/2/2014                             *
* Assignment: Project 5: Matrices             *
***********************************************
* Mutiplies two matricies                     *
***********************************************/

#include "matrix.h"

Matrix::Matrix(int row, int col) {
  rows = row;
  cols = col;
  arr = new int*[row];
  for (int r=0; r < rows; r++) {
    arr[r] = new int[col];
    for (int c=0; c < cols; c++) {
      arr[r][c] = 0;
    }
  }
}

Matrix::~Matrix(void) {
  for (int r=0; r < rows; r++) {
    delete [] arr[r];
  }
  delete arr;
}
void Matrix::setElem(int row, int col, int data) {
  if (row < rows && row >= 0 && col < cols && col >= 0) {
    arr[row][col] = data;
  }
}

int Matrix::getElem(int row, int col) {
  if (row < rows && row >= 0 && col < cols && col >= 0) {
    return arr[row][col];
  }
}

void Matrix::print(void) {
  for (int r=0; r < this->getRows(); r++) {
    for (int c=0; c < cols; c++) {
      std::cout << arr[r][c] << " ";
    }
    std::cout << std::endl;
  }
}

Matrix* Matrix::times(Matrix* o) {
  Matrix* ret = new Matrix(this->rows, o->getCols());
  for (int r = 0; r < this->rows; r++) {
    for (int c = 0; c < o->getCols(); c++) {
      int total = 0;
      for (int d = 0; d < this->cols; d++) {
        total = (total + (this->getElem(r, d) * o->getElem(d, c)));
      }
      ret->setElem(r, c, total);
    }
  }
  return ret;
}

int Matrix::getRows(void) {
  return rows;
}

int Matrix::getCols(void) {
  return cols;
}
