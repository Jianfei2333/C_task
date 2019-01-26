// 561
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void qsort(vector<int>& nums, int left, int right) {
  // left < right
  // cout << "left: " << left << ", right: " << right << endl;
  int anchor = nums[left];
  int p_left = left, p_right = right;
  while (p_left < p_right) {
    while (nums[p_right] >= anchor && p_left < p_right) p_right --;
    if (p_left == p_right) break;
    nums[p_left] = nums[p_right];
    nums[p_right] = anchor;
    while (nums[p_left] < anchor && p_left < p_right) p_left ++;
    if (p_left == p_right) break;
    nums[p_right] = nums[p_left];
    nums[p_left] = anchor;
  }
  if (p_left - left > 1) qsort(nums, left, p_left - 1);
  if (right - p_right > 1) qsort(nums, p_right + 1, right);
}

int arrayPairSum(vector<int>& nums) {
  qsort(nums, 0, nums.size() - 1);
  int sum = 0;
  for (int i = 0; i < nums.size(); i ++, i++) {
    sum += nums[i];
  }
  return sum;
}

int main() {
  vector<int> nums = {4,5,1,9,5,7};
  qsort(nums, 0, nums.size()-1);
  for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter ++) {
    cout << *iter << ' ';
  }
  cout << endl;
  cout << arrayPairSum(nums);
}