/**********************************************
*	Name:	Richard Petrie												*																																														 *
*	Date:	10/26/2014														*																																											*
*	Assignment:	Project	4:	Fractions						*																																		*
***********************************************
*	Math with Fractions in C++!									*
***********************************************/

#include "fraction.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//Runs the program and does programmy stuff
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
  cin >> botN;
  one.setValues(topN, botN);

  //Operator
  cin >> op;

  //Second fraction
  getline(cin, top, '/');
  topN = atoi(top.c_str());
  cin >> botN;
  two.setValues(topN, botN);

  //Operator handeling
  if (op == '+') {
    ans = one.plus(two);
  }
  else if (op == '-') {
    ans = one.minus(two);
  }
  else if (op == '*') {
    ans = one.times(two);
  }
  else if (op == '/') {
    ans = one.divide(two);
  }
  else
  {
    cerr << "Invalid operator\n";
    return 1;
  }

  ans.print();

  return 0;
}
