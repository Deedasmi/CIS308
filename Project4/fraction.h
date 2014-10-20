/**********************************************
*	Name:	Richard Petrie												*																																														 *
*	Date:	10/26/2014														*																																											*
*	Assignment:	Project	4:	Fractions						*																																		*
***********************************************
*	Math with Fractions in C++!									*
***********************************************/

#ifndef FRACTION_H
#define FRACTION_H

//Class that handels the fractions, and the math.
class Fraction {
public:
  void setValues(int, int);
  Fraction plus(Fraction);
  Fraction minus(Fraction);
  Fraction times(Fraction);
  Fraction divide(Fraction);
  void reduce(void);
  void print(void);
private:
  int top;
  int bot;
};

#endif
