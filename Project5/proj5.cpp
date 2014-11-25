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

int main() {
  cout << "Enter first matrix (use // to denote new rows): " << endl;
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
        cout << endl << "Saving " << d << " from " << matrixRow.str() << endl;
        temp.push_back(d);
        pos2++;
        matrixRow.str(matrixRow.str().erase(0, pos2));
    }

    mat.push_back(temp);
  }
  vector<int> temp;
  int pos2 = 0;
  getline(matrix, row, '/');
  stringstream matrixRow(row);
  while ((pos2 = matrixRow.str().find(" ")) != -1) {
    string s;
    int d = 0;
    matrixRow << s;
    stringstream ss(s);
    ss >> d;
    temp.push_back(d);
    pos2++;
    matrixRow.str(matrixRow.str().erase(0, pos2));
  }
  mat.push_back(temp);
  //cout << endl << mat.size() << endl << mat.at(1).size();
  cout << "Data in mat(1)" << endl;
  for(int i = 0; i < mat.at(1).size(); i++ ) {
    cout << mat.at(1).at(i) << " ";
  }


  /*
  getline(cin, line);
  stringstream matrix (line);



  while (matrix.str() != "") {
  //Parse input for rows
  getline(matrix, row, '/');
  stringstream matrixRow (row);

  //Update line with removed row
  int pos = matrix.str().find("//");
  pos = pos + 2;
  matrix.str(matrix.str().erase(0, pos));

  while (matrixRow.str() != "") {

  }


  cout << endl << matrix.str() << endl << matrixRow.str();
}*/
}
