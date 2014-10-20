#include "fraction.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  string top;
  int topN;
  int botN;
  char op;
  Fraction one = Fraction();
  Fraction two = Fraction();
  Fraction ans = Fraction();
  cout << "Enter an equation. Ex: 1/2 * 3/4" << endl;

  //First fraction
  getline(cin, top, '/');
  topN = atoi(top.c_str());
  //stringstream ss(top);
  //ss >> topN;
  cin >> botN;
  one.setValues(topN, botN);

  //Operator
  cin >> op;

  //Second fraction
  getline(cin, top, '/');
  topN = atoi(top.c_str());
  //stringstream ss(top);
  //ss >> topN;
  cin >> botN;
  two.setValues(topN, botN);

  if (op == '+') {
    ans = one.plus(two);
  }
  if (op == '-') {
    ans = one.minus(two);
  }
  if (op == '*') {
    ans = one.times(two);
  }
  if (op == '/') {
    ans = one.divide(two);
  }

  ans.print();
  return 0;
}
