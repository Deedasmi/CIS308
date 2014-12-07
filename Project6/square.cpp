#include "square.h"
#include <iostream>

Square::Square(std::string content) {
  key = new char*[5];
  for (int i = 0; i < 5; i++) {
    key[i] = new char[5];
    for (int k = 0; k < 5; k++) {
      key[i][k] = 'a';
    }
  }
  bool* hasChar = new bool[25];
  int x = 0;
  int y = 0;
  for (int i = 0; i < content.length(); i++) {
    char c = std::tolower(content[i]);
    //std::cout << c;
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
}

int* Square::getPos(char c) {
  for (int i = 0; i < 5; i++) {
    for (int k = 0; k < 5; k++) {
      if (getChar(i,k) == c) {
        return new int[2] {i, k};
      }
    }
  }
}

int Square::convert(char c) {
  int ret = c - 'a';
  if (c > 'q') {
    return ++ret;
  }
  return ret;
}

char Square::convert(int c) {
  char ret = (char)(c + 'a');
  if (c > 'q') {
    return ++ret;
  }
  return ret;
}

void Square::print() {
  for (int i = 0; i < 5; i++) {
    for (int k = 0; k < 5; k++) {
      std::cout << getChar(i,k);
    }
    std::cout << std::endl;
  }
  //std::cout << key[4,4]
}

Square::~Square() {
  for (int i = 0; i < 5; i++) {
    //delete [] key[i];
  }
  //delete [] key;
}
