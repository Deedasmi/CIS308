/**********************************************
* Name: Richard Petrie                        *
* Date: 12-07-2014                            *
* Assignment: Project 6: Cipher               *
***********************************************
* Encrypts and Decrypts a string based        *
* on a block cipher input by the user         *
***********************************************/

#include "cipher.h"
#include <iostream>

//Constructor. Nothing is using new.
Cipher::Cipher(std::string c1, std::string c2) {
  plain1 = Square();
  plain2 = Square();
  cipher1 = Square(c1);
  cipher2 = Square(c2);
}

//Encryption
std::string Cipher::encrypt(std::string phrase) {
  for (int i = 0; i < phrase.length(); i = i + 2) {
    int* pos1 = plain1.getPos(phrase[i]);
    int* pos2 = plain2.getPos(phrase[i + 1]);
    phrase[i] = cipher1.getChar(pos1[0], pos2[1]);
    phrase[i + 1] = cipher2.getChar(pos2[0], pos1[1]);
    delete pos2;
    delete pos1;
  }
  std::cout << std::endl;
  cipher1.print();
  std::cout << std::endl;
  cipher2.print();
  return phrase;
}

//Decryption
std::string Cipher::decrypt(std::string phrase) {
  for (int i = 0; i < phrase.length(); i = i + 2) {
    int* pos1 = cipher1.getPos(phrase[i]);
    int* pos2 = cipher2.getPos(phrase[i + 1]);
    phrase[i] = plain1.getChar(pos1[0], pos2[1]);
    phrase[i + 1] = plain2.getChar(pos2[0], pos1[1]);
    delete pos2;
    delete pos1;
  }
  std::cout << std::endl;
  cipher1.print();
  std::cout << std::endl;
  cipher2.print();
  return phrase;
}
