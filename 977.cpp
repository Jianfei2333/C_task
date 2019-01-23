// 977
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& A) {
  vector<int>::iterator left, right;
  if (A[0] >= 0) {
    left = A.begin() - 1;
    right = A.begin();
  } else if (A[A.size()-1] <= 0) {
    left = A.end() - 1;
    right = A.end();
  } else {
    for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter ++) {
      if (*iter < 0 && *(iter + 1) >= 0) {
        left = iter;
        right = iter + 1;
      }
    }
  }
  vector<int> squares;
  for (; right != A.end() && left >= A.begin();) {
    int leftSquare = *left * *left;
    int rightSquare = *right * *right;
    if (leftSquare < rightSquare) {
      squares.push_back(leftSquare);
      left --;
    } else {
      squares.push_back(rightSquare);
      right ++;
    }
  }
  for (; right != A.end(); right ++) {
    squares.push_back(*right * *right);
  }
  for (; left >= A.begin(); left --) {
    squares.push_back(*left * *left);
  }
  return squares;
}

int main () {
  vector<int> data {-7, -3, 0, 3, 4};
  vector<int> ret = sortedSquares(data);
  for (vector<int>::iterator iter = ret.begin(); iter != ret.end(); iter ++) {
    cout << *iter << ' ';
  }
}