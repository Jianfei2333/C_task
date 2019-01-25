// 942
#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& list, int left, int right) {
  for (;left <= right; left ++, right --) {
    int t = list[left];
    list[left] = list[right];
    list[right] = t;
  }
}

vector<int> diStringMatch(string S) {
  S.push_back('I');
  vector<int> res;
  for (int i = 0; i < S.size(); i++) {
    res.push_back(i);
  }

  int count = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] != 'I') count ++;
    else {
      reverse(res, i-count, i);
      count = 0;
    }
  }
  return (res);
}

int main () {
  string S = "DIDI";
  vector<int> res = diStringMatch(S);
  for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter ++) {
    cout << *iter << ' ';
  }
}