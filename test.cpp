// 933
#include <iostream>
#include <vector>

using namespace std;

class RecentCounter {
  public:
    vector<int> pings;
    RecentCounter():pings(0) {
      
    }
  
    int ping(int t) {
      pings.push_back(t);
      int count = 0;
      for (vector<int>::iterator iter = pings.end() - 1; iter >= pings.begin(); iter --) {
        if (*iter >= t-3000) count++;
        else break;
      }
      return count;
    }
};

int main () {
  RecentCounter* obj = new RecentCounter();
  cout << obj -> pings.size();
  // for (vector<int>::iterator iter = obj->pings.begin(); iter < obj->pings.end(); iter ++) {
    // cout << *iter << ' ';
  // }
  cout << obj -> ping(1) << ' ' << obj -> ping(100) << ' ' << obj -> ping(3001) << ' ' << obj -> ping(3002) << endl;
}