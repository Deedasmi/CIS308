#include "fraction.h"
#include <iostream>

using namespace std;

void Fraction::setValues(int t, int b)
{
  top = t;
  bot = b;
}

Fraction Fraction::plus(Fraction f)
{

}
Fraction Fraction::minus(Fraction f)
{

}
Fraction Fraction::times(Fraction f)
{
  Fraction ret = Fraction();
  int nTop = this->top * f.top;
  int nBot = this->bot * f.bot;
  ret.setValues(nTop, nBot);
  ret.reduce();
  return ret;
}
Fraction Fraction::divide(Fraction f)
{

}
void Fraction::print()
{
  cout << "Answer is: " << top << "/" << bot << endl;;
}

void Fraction::reduce()
{

}
