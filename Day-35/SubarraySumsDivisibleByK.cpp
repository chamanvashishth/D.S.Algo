class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remainderCount(k, 0);
        remainderCount[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            int remainder = ((prefixSum % k) + k) % k;

            count += remainderCount[remainder];
            remainderCount[remainder]++;
        }

        return count;
    }
};