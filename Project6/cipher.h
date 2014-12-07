#ifndef CIPHER_H
#define CIPHER_H

#include "square.h"

class Cipher {
public:
  Cipher(std::string, std::string);
  //S~Cipher(void);
  std::string encrypt(std::string);
  std::string decrypt(std::string);
private:
  Square plain1;
  Square plain2;
  Square cipher1;
  Square cipher2;
};

#endif
