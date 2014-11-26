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
    cerr << "Invalid matrices" << endl;
    return 1;
  }
  Matrix* ans = m1->times(m2);
  ans->print();
}

Matrix* readMatrix(void) {
  string line;
  string row;
  vector<vector<int> > mat;
  getline(cin, line);
  stringstream matrix (line);
  int pos = 0;
  while ((pos = matrix.str().find("//")) != -1) {
      getline(matrix, row, '/');
      stringstream matrixRow (row);

      //Update line with removed row
      pos = pos + 3;
      matrix.str(matrix.str().erase(0, pos));

      //cout << matrix.str() << " ";
      int pos2 = 0;
      //cout << matrix.str();
      //cin.ignore();
      vector<int> temp;
      while ((pos2 = matrixRow.str().find(" ")) != -1) {
        string s;
        int d = 0;
        matrixRow >> s;
        stringstream ss(s);
        ss >> d;
        //cout << endl << "Saving " << d << " from " << matrixRow.str() << endl;
        temp.push_back(d);
        pos2++;
        matrixRow.str(matrixRow.str().erase(0, pos2));
    }

    mat.push_back(temp);
  }
  vector<int> temp;
  int pos2 = 0;
  //getline(matrix, row, '/');
  stringstream matrixRow(matrix.str());
  matrixRow.str(matrixRow.str().append(" "));
  while ((pos2 = matrixRow.str().find(" ")) != -1) {
    string s;
    int d = 0;
    matrixRow >> s;
    stringstream ss(s);
    ss >> d;
    //cout << endl << "Saving " << d << " from " << matrixRow.str() << endl;
    temp.push_back(d);
    pos2++;
    matrixRow.str(matrixRow.str().erase(0, pos2));
    //cout << matrixRow.str();
  }
  mat.push_back(temp);

  int size = mat.at(0).size();
  for (int i = 0; i < mat.size(); i++) {
    if(mat.at(i).size() != size) {
      cerr << "Invalid matrix";
      throw 1;
    }
  }
  Matrix* ret = new Matrix(mat.size(), size);
  for (int i = 0; i < mat.size(); i++) {
    for (int d = 0; d < mat.at(i).size(); d++) {
      ret->setElem(i, d, mat.at(i).at(d));
    }
  }
  return ret;
}
