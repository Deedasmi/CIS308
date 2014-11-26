/**********************************************
* Name: Richad Petrie                         *
* Date: 12/2/2014                             *
* Assignment: Project 5: Matrices             *
***********************************************
* Mutiplies two matricies                     *
***********************************************/

#include "matrix.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Matrix* readMatrix(void);

int main() {
  cout << "Enter first matrix (use // to denote new rows): " << endl;
  Matrix* m1 = readMatrix();
  cout << "Enter second matrix (use // to denote new rows): " << endl;
  Matrix* m2 = readMatrix();

  if(m1->getCols() != m2->getRows()) {
    cerr << "Invalid matrices" << endl << "Rows of m1 does not match cols of m2" << endl;
    throw 2;
  }
  Matrix* ans = m1->times(m2);
  ans->print();
  delete m1;
  delete m2;
  delete ans;
}

Matrix* readMatrix(void) {
  string line;
  string row;
  //Using vectors to have easy size to initialize matrix
  vector<vector<int> > mat;
  getline(cin, line);
  stringstream matrix (line);
  int pos = 0;
  while ((pos = matrix.str().find("//")) != -1) {
      getline(matrix, row, '/');
      stringstream matrixRow (row);
      //Skip "// "
      pos = pos + 3;
      matrix.str(matrix.str().erase(0, pos));
      int pos2 = 0;
      vector<int> temp;
      while ((pos2 = matrixRow.str().find(" ")) != -1) {
        //Convert to number
        string s;
        int d = 0;
        matrixRow >> s;
        stringstream ss(s);
        ss >> d;

        //Add number to vector
        temp.push_back(d);
        pos2++;
        matrixRow.str(matrixRow.str().erase(0, pos2));
    }
    //Add vector to vector
    mat.push_back(temp);
  }
  vector<int> temp;
  int pos2 = 0;
  stringstream matrixRow(matrix.str());
  matrixRow.str(matrixRow.str().append(" "));
  while ((pos2 = matrixRow.str().find(" ")) != -1) {
    //Convert to number
    string s;
    int d = 0;
    matrixRow >> s;
    stringstream ss(s);
    ss >> d;

    //Add number to vector
    temp.push_back(d);
    pos2++;
    matrixRow.str(matrixRow.str().erase(0, pos2));
  }
  mat.push_back(temp);

  //Check to see if column sizes are consistant
  int size = mat.at(0).size();
  for (int i = 0; i < mat.size(); i++) {
    if(mat.at(i).size() != size) {
      cerr << "Invalid matrix" << endl << "Columns different sizes" << endl;
      throw 1;
    }
  }
  //Fill matrix with vector data
  Matrix* ret = new Matrix(mat.size(), size);
  for (int i = 0; i < mat.size(); i++) {
    for (int d = 0; d < mat.at(i).size(); d++) {
      ret->setElem(i, d, mat.at(i).at(d));
    }
  }
  return ret;
}
