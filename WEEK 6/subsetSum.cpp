#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int>& nums, int target, int index, int sum, vector<int>& subset) {
  if (sum == target) {
    return true;
  }
  if (index == nums.size() || sum > target) {
    return false;
  }
  
  sum += nums[index];
  subset.push_back(nums[index]);
  
  if (subsetSum(nums, target, index + 1, sum, subset)) {
    return true;
  }
  
  sum -= nums[index];
  subset.pop_back();
  
  return subsetSum(nums, target, index + 1, sum, subset);
}

int main() {
  
  vector<int> nums;
  int n, target;

  cout << "Masukkan ukuran set: ";
  cin >> n;
  cout << "Masukkan elemen set: ";

  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    nums.push_back(num);
  }

  cout << "Masukkan target: ";
  cin >> target;
  vector<int> subset;

  if (subsetSum(nums, target, 0, 0, subset)) {
    cout << "True" << endl;
    cout << "Subset: ";
    for (int num : subset) {
    cout << num << " ";
    }

    cout << endl;
  }   else {
      cout << "False" << endl;
  }
  
  return 0;
}