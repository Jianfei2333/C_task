// 657
#include <iostream>
#include <vector>

using namespace std;

bool judgeCircle(string moves) {
  int x = 0, y = 0;
  for (string::iterator iter = moves.begin(); iter != moves.end(); iter ++) {
    switch(*iter) {
      case 'U' : y++; break;
      case 'D' : y--; break;
      case 'L' : x--; break;
      case 'R' : x++; break;
    }
  }
  return (x == 0 && y == 0);
}

int main () {
  string moves = "UD";
  bool res = judgeCircle(moves);
  cout << (res ? "true" : "false");
}