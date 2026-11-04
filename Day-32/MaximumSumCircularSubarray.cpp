class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxEndingHere = 0;
        int minEndingHere = 0;
        int maxSum = nums[0];
        int minSum = nums[0];

        for (int num : nums) {
            totalSum += num;

            maxEndingHere = max(num, maxEndingHere + num);
            maxSum = max(maxSum, maxEndingHere);

            minEndingHere = min(num, minEndingHere + num);
            minSum = min(minSum, minEndingHere);
        }

        if (maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};