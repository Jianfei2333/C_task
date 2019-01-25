// 832
#include <iostream>
#include <vector>

using namespace std;

void flipAndInvertRow(vector<int>& row) {
  vector<int>::iterator left = row.begin(), right = row.end() - 1;
  while (left <= right) {
    int t = *left == 0 ? 1 : 0;
    *left = *right == 0 ? 1 : 0;
    *right = t;
    left ++;
    right --;
  }
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
  for (vector<vector<int>>::iterator iter = A.begin(); iter != A.end(); iter ++) {
    flipAndInvertRow(*iter);
  }
  return A;
}

int main () {
  vector<vector<int>> A {{1,1,0},{1,0,1},{0,0,0}};
  vector<vector<int>> result = flipAndInvertImage(A);
  for (vector<vector<int>>::iterator iter = result.begin(); iter != result.end(); iter ++) {
    for (vector<int>::iterator iter2 = iter -> begin(); iter2 != iter -> end(); iter2 ++) {
      cout << *iter2 << " ";
    }
    cout << endl;
  }
}