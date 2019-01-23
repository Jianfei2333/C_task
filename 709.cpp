// 709
#include <iostream>
using namespace std;

string toLowerCase(string str) {
  string out;
  for (string::iterator iter = str.begin(); iter != str.end(); iter ++) {
    // cout << *iter + 0 << char(*iter+32) << endl;
    if (*iter + 0 <= int('Z') && *iter + 0 >= int('A')) out.push_back(char(*iter + 32));
    else out.push_back(*iter);
  }
  return out;
}

int main () {
  cout << toLowerCase("Apply") << endl;
}