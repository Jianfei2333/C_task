// 852
#include <iostream>
#include <vector>

using namespace std;


int peakIndexInMountainArray(vector<int>& A) {
  for (int i = 1; i < A.size(); i ++) {
    if (A[i] > A[i-1]) continue;
    else return (i-1);
  }
  return 1;
}

int main () {
  vector<int> A {3,4,5,1};
  cout << peakIndexInMountainArray(A);
}