#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    vector<int> tails;

    for (int x : nums) {
        int low = 0;
        int high = tails.size();
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (tails[mid] < x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (low == tails.size()) {
            tails.push_back(x);
        } else {
            tails[low] = x;
        }
    }

    return tails.size();
}

signed main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << lengthOfLIS(nums) << endl;

    return 0;
}