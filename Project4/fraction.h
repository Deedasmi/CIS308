#ifndef FRACTION_H
#define FRACTION_H

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
