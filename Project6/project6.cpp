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
#include <algorithm>

using namespace std;

int main() {
  string k1;
  string k2;
  string phrase;
  cout << "Enter a key: " << endl;
  getline(cin, k1);
  k1.erase(remove(k1.begin(), k1.end(), ' '), k1.end());

  cout << "Enter a key: " << endl;
  getline(cin, k2);
  k2.erase(remove(k2.begin(), k2.end(), ' '), k2.end());

  cout << "Enter e to encrypt or d to decrypt: " << endl;
  char eord;
  cin.get(eord);
  eord = tolower(eord);

  cout << "Enter a phrase: " << endl;
  cin.ignore();
  getline(cin, phrase);
  phrase.erase(remove(phrase.begin(), phrase.end(), ' '), phrase.end());

  if (k1.find('q') != -1 || k1.find('Q') != -1 || k2.find('q') != -1 || k2.find('Q') != -1 || phrase.find('q') != -1 || phrase.find('Q') != -1) {
    cout << "No Q's";
    throw 1;
  }

  if (phrase.length() % 2 != 0 || k1.length() > 25 || k2.length() > 25) {
    cout << "Please only even number of characters less than 25 (not including spaces)";
    throw 2;
  }

  Cipher stuff = Cipher(k1, k2);
  string out;
  if (eord == 'e') {
    out = stuff.encrypt(phrase);
  } else if(eord == 'd') {
    out = stuff.decrypt(phrase);
  } else {
    cout << "Invalid char";
    throw 3;
  }
  cout << "New string: " << out << endl;

  return 0;
}
