// 905
#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
  vector<int>::iterator left = A.begin(), right = A.end()-1;
  while (left != right) {
    if (*left % 2 == 0) left++;
    else {
      cout << "left " << *left << endl;
      if (*right % 2 == 1) right--;
      else {
        cout << "right " << *right << endl;
        int t = *left;
        *left = *right;
        *right = t;
      }
    }
  }
  return A;
}

int main () {
  vector<int> A {1, 2, 3, 4, 5, 6, 7};
  vector<int> result = sortArrayByParity(A);
  for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter ++) {
    cout << *iter << " ";
  }
}