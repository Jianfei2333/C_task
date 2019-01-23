// 961
#include <iostream>
#include <vector>
using namespace std;

int repeatedNTimes(vector<int>& A) {
  bool state[10000] = {false};
  for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter ++) {
    if (state[*iter] == false) state[*iter] = true;
    else return *iter;
  }
}

int main () {
  vector<int> A{5,1,5,2,5,3,5,4};
  cout << repeatedNTimes(A) << endl;
}