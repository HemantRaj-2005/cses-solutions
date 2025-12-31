#include <bits/stdc++.h>

using namespace std;

long long findMissingNumber(long long n, const vector<long long>& nums) {

  long long expected_sum = n * (n + 1) / 2;
  long long actual_sum = 0;
  for (long long num : nums) {
    actual_sum += num;
  }
  return expected_sum - actual_sum;
}

int main() {
  long long n;
  cin >> n;

  vector<long long> nums(n - 1);
  for (long long i = 0; i < n - 1; ++i) {
    cin >> nums[i];
  }

  long long missing = findMissingNumber(n, nums);
  cout << missing << endl;

  return 0;
}
