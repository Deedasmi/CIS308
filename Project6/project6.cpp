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
  char c;
  cin.get(c);
  c = tolower(c);
  cout << "Enter a phrase: " << endl;
  cin.ignore();
  getline(cin, phrase);
  phrase.erase(remove(phrase.begin(), phrase.end(), ' '), phrase.end());
  if (k1.find('q') != -1 || k1.find('Q') != -1 || k2.find('q') != -1 || k2.find('Q') != -1 || phrase.find('q') != -1 || phrase.find('Q') != -1) {
    cout << "No Q's";
    throw 1;
  }
  //e or d

  if (phrase.length() % 2 != 0 || k1.length() > 25 || k2.length() > 25) {
    cout << "Please only even number of characters less than 25 (not including spaces)";
    throw 2;
  }
  Cipher stuff = Cipher(k1, k2);
  string out;
  if (c == 'e') {
    out = stuff.encrypt(phrase);
  } else if(c == 'd') {
    out = stuff.decrypt(phrase);
  } else {
    cout << "Invalid char";
    throw 3;
  }
  cout << "New string: " << out << endl;

  return 0;
}
