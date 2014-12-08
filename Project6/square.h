/**********************************************
* Name: Richard Petrie                        *
* Date: 12-07-2014                            *
* Assignment: Project 6: Cipher               *
***********************************************
* Encrypts and Decrypts a string based        *
* on a block cipher input by the user         *
***********************************************/

#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square {
public:
  Square(std::string);
  Square(void) : Square("abcdefghijklmnoprstuvwxyz") {};
  int* getPos(char);
  char getChar(int x, int y) { return key[x][y];};
  void print();
private:
  char key[5][5];
  int convert(char);
  char convert(int);
};

#endif
