/**********************************************
* Name: Richard Petrie                        *
* Date: 12-07-2014                            *
* Assignment: Project 6: Cipher               *
***********************************************
* Encrypts and Decrypts a string based        *
* on a block cipher input by the user         *
***********************************************/

#ifndef CIPHER_H
#define CIPHER_H

#include "square.h"

class Cipher {
public:
  Cipher(std::string, std::string);
  std::string encrypt(std::string);
  std::string decrypt(std::string);
private:
  Square plain1;
  Square plain2;
  Square cipher1;
  Square cipher2;
};

#endif
