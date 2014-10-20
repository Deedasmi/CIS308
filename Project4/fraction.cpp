/**********************************************
*	Name:	Richard Petrie												*																																														 *
*	Date:	10/26/2014														*																																											*
*	Assignment:	Project	4:	Fractions						*																																		*
***********************************************
*	Math with Fractions in C++!									*
***********************************************/

#include "fraction.h"
#include <iostream>

using namespace std;
//Sets values of the fraction. Bassically our initializer
void Fraction::setValues(int t, int b)
{
  top = t;
  bot = b;
}
//Finds a common denominator, then adds functions
Fraction Fraction::plus(Fraction f)
{
  //Common denominator
  if (this->bot != f.bot) {
    int ftb = f.bot
    f.top = f.top * this->bot;
    f.bot = f.bot * this->bot;
    this->top = this->top * ftb;
    this->bot = this->bot * ftb;
    
  }
  Fraction ret =Fraction();
  int nTop = this->top + f.top;
  ret.setValues(nTop, f.bot);
  ret.reduce();
  return ret;

}
//Finds a common denominator, then subtracts fractions
Fraction Fraction::minus(Fraction f)
{
  //Common denominator
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
//Multiples the calling fraction by the parameter fraction
Fraction Fraction::times(Fraction f)
{
  Fraction ret = Fraction();
  int nTop = this->top * f.top;
  int nBot = this->bot * f.bot;
  ret.setValues(nTop, nBot);
  ret.reduce();
  return ret;
}
//Slips the parameter function and multiplies it by calling fraction
Fraction Fraction::divide(Fraction f)
{
  int temp = f.bot;
  f.bot = f.top;
  f.top = temp;
  this->times(f);

}
//Prints the value of the fraction that called the function
void Fraction::print()
{
  if (this->top == this->bot) {
    cout << "Answer is: " << top << endl;
  } else {
    cout << "Answer is: " << top << "/" << bot << endl;
  }
}
//Reduced the fraction that called the function.
void Fraction::reduce()
{
  //If it is divisible by 3
  while (this->bot % 3 == 0) {
    if (this->top % 3 != 0) {
      break;
    }
    this->bot = this->bot / 3;
    this->top = this->top /3;
  }
  //If it is divisible by 2
  while (this->bot % 2 == 0) {
    if (this->top % 2 != 0) {
      break;
    }
    this->bot = this->bot /2;
    this->top = this->top /2;
  }
  //If it can be reduced fully.
  if (this-> bot % this->top == 0) {
    this->bot = this->bot / this->top;
    this->top = 1;
  }
}
