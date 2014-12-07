#include "cipher.h"
#include <iostream>

Cipher::Cipher(std::string c1, std::string c2) {
  plain1 = Square();
  plain2 = Square();
  cipher1 = Square(c1);
  cipher2 = Square(c2);
}

std::string Cipher::encrypt(std::string phrase) {
  for (int i = 0; i < phrase.length(); i = i + 2) {
    int* pos1 = plain1.getPos(phrase[i]);
    int* pos2 = plain2.getPos(phrase[i + 1]);
    phrase[i] = cipher1.getChar(pos1[0], pos2[1]);
    phrase[i + 1] = cipher2.getChar(pos2[0], pos1[1]);
    delete pos2;
    delete pos1;
  }
  return phrase;
}

std::string Cipher::decrypt(std::string phrase) {
  for (int i = 0; i < phrase.length(); i = i + 2) {
    int* pos1 = cipher1.getPos(phrase[i]);
    int* pos2 = cipher2.getPos(phrase[i + 1]);
    phrase[i] = plain1.getChar(pos1[0], pos2[1]);
    phrase[i + 1] = plain2.getChar(pos2[0], pos1[1]);
    delete pos2;
    delete pos1;
  }
  return phrase;
}
