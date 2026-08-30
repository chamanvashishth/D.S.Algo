#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < n - 1 && nums[left] <= nums[left + 1]) {
            left++;
        }

        if (left == n - 1) {
            return 0;
        }

        while (right > 0 && nums[right] >= nums[right - 1]) {
            right--;
        }

        int minValue = nums[left];
        int maxValue = nums[left];

        for (int i = left; i <= right; i++) {
            minValue = min(minValue, nums[i]);
            maxValue = max(maxValue, nums[i]);
        }

        while (left > 0 && nums[left - 1] > minValue) {
            left--;
        }

        while (right < n - 1 && nums[right + 1] < maxValue) {
            right++;
        }

        return right - left + 1;
    }
};
