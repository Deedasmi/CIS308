/**********************************************
* Name: Richard Petrie                        *
* Date: 12-07-2014                            *
* Assignment: Project 6: Cipher               *
***********************************************
* Encrypts and Decrypts a string based        *
* on a block cipher input by the user         *
***********************************************/

#include "square.h"
#include <iostream>

//Constructor
Square::Square(std::string content) {
  for (int i = 0; i < 5; i++) {
    for (int k = 0; k < 5; k++) {
      key[i][k] = 'a';
    }
  }
  bool* hasChar = new bool[25];
  for (int i = 0; i < 25; i++) {
    hasChar[i] = 0;
  }
  int x = 0;
  int y = 0;
  for (int i = 0; i < content.length(); i++) {
    char c = std::tolower(content[i]);
    if (!hasChar[convert(c)]) {
      key[x][y] = c;
      hasChar[convert(c)] = 1;
      if(y == 4) {
        x++;
        y = 0;
      } else {
        y++;
      }
    }
  }
  //Custom string in
  //Fill remaining
  for (x; x < 5; x++) {
    for (y; y < 5; y++) {
      int i = 0;
      while(hasChar[i]) {
        i++;
      }
      key[x][y] = convert(i);
      hasChar[i] = 1;
    }
    y = 0;
  }
  delete [] hasChar;
}

//Get position of a character
int* Square::getPos(char c) {
  for (int i = 0; i < 5; i++) {
    for (int k = 0; k < 5; k++) {
      if (getChar(i,k) == c) {
        return new int[2] {i, k};
      }
    }
  }
}

//Convert a character into a number 0-25
int Square::convert(char c) {
  int ret = c - 'a';
  if (c >= 'q') {
    return --ret;
  }
  return ret;
}

//Convert an integer to a character a-z but not q
char Square::convert(int c) {
  if (c >= 16) { //If it's bigger than q
    char ret = (char)(c + 'b');
    return ret;
  }

  char ret = (char)(c + 'a');
  return ret;
}

//Print function for troubleshooting
void Square::print() {
  for (int i = 0; i < 5; i++) {
    for (int k = 0; k < 5; k++) {
      std::cout << getChar(i,k);
    }
    std::cout << std::endl;
  }
}

//Destructor
Square::~Square() {
}
