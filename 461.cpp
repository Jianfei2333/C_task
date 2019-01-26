// 461
#include <iostream>
#include <vector>

using namespace std;

int hammingDistance(int x, int y) {
  int dis = x ^ y;
  int count = 0;
  while (dis != 0) {
    if (dis % 2 == 1) count ++;
    dis = dis / 2;
  }
  return count;
}

int main () {
  int x = 1, y = 4;
  cout << hammingDistance(x, y);
  
}