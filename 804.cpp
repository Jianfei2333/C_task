// 804
#include <iostream>
#include <vector>
using namespace std;

const string table[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

string encrypt(string s) {
  string newWord;
  for (string::iterator iter = s.begin(); iter != s.end(); iter ++) {
    newWord.append(table[int(*iter - 'a')]);
  }
  return newWord;
}

bool unique(vector<string>& list, string word) {
  for (vector<string>::iterator iter = list.begin(); iter != list.end(); iter ++) {
    if (word == *iter) return false;
  }
  return true;
}

int uniqueMorseRepresentations(vector<string>& words) {
  vector<string> encrypted;
  for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter ++) {
    string wordEncrypted = encrypt(*iter);
    if (unique(encrypted, wordEncrypted)) {
      encrypted.push_back(wordEncrypted);
    }
  }
  return (encrypted.size());
}

int main () {
  vector<string> words {"gin", "zen", "gig", "msg"};
  cout << uniqueMorseRepresentations(words) << endl;
}