// 944
#include <iostream>
#include <vector>

using namespace std;

int minDeletionSize(vector<string>& A) {
  int length = A[0].size();
  int count = 0;
  for (int i = 0; i < length; i ++) {
    for (int j = 0; j < A.size() - 1; j ++) {
      if (A[j][i] > A[j+1][i]) {
        count ++;
        break;
      }
    }
  }
  return count;
}

int main () {
  vector<string> A = {"cba","daf","ghi"};
  int r = minDeletionSize(A);
  cout << r;
}