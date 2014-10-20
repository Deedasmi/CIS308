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
  if (this->bot != f.bot) {
    this->top = this->top * f.bot;
    this->bot = this->bot * f.bot;
    f.top = f.top * this->bot;
    f.bot = f.bot * this->bot;
  }
  Fraction ret =Fraction();
  int nTop = this->top + f.top;
  ret.setValues(nTop, f.bot);
  ret.reduce();
  return ret;

}
Fraction Fraction::minus(Fraction f)
{
  if (this->bot != f.bot) {
    this->top = this->top * f.bot;
    this->bot = this->bot * f.bot;
    f.top = f.top * this->bot;
    f.bot = f.bot * this->bot;
  }
  Fraction ret =Fraction();
  int nTop = this->top - f.top;
  ret.setValues(nTop, f.bot);
  ret.reduce();
  return ret;
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
  int temp = f.bot;
  f.bot = f.top;
  f.top = temp;
  this->times(f);

}
void Fraction::print()
{
  cout << "Answer is: " << top << "/" << bot << endl;;
}

void Fraction::reduce()
{
  while (this->bot % 3 == 0) {
    if (this->top % 3 != 0) {
      break;
    }
    this->bot = this->bot / 3;
    this->top = this->top /3;
  }
  while (this->bot % 2 == 0) {
    if (this->top % 2 != 0) {
      break;
    }
    this->bot = this->bot /2;
    this->top = this->top /2;
  }
  if (this-> bot % this->top == 0) {
    this->bot = this->bot / this->top;
    this->top = 1;
  }
}
