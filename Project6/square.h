#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square {
public:
  Square(std::string);
  Square(void) : Square("abcdefghijklmnoprstuvwxyz") {};
  ~Square();
  int* getPos(char);
  char getChar(int x, int y) { return key[x][y];};
  void print();
private:
  char** key;
  int convert(char);
  char convert(int);
};

#endif
