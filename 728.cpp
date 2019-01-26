// 728
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool selfDivided(int t) {
  int v = t;
  while (v) {
    int divide = v%10;
    if (divide == 0) return false;
    else if (t % divide != 0) return false;
    v /= 10;
  }
  return true;
}

vector<int> selfDividingNumbers(int left, int right) {
  vector<int> res;
  for (int i = left; i <= right; i ++) {
    if (selfDivided(i)) res.push_back(i);
  }
  return (res);
}

int main () {
  int left = 1, right = 22;
  vector<int> res = selfDividingNumbers(left, right);
  for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter ++) {
    cout << *iter << ' ';
  }
}