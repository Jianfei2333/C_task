// 771
#include <iostream>
using namespace std;

int numJewelsInStones(string J, string S) {
  int count = 0;
  for (string::iterator iterS = S.begin(); iterS != S.end(); iterS++) {
    for (string::iterator iterJ = J.begin(); iterJ != J.end(); iterJ++) {
      if (*iterJ == *iterS) {
        count ++;
        break;
      }
    }
  }
  return count;
}

int main () {
  return 0;
}