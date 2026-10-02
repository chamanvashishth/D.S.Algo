class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> first;
        first[0] = -1;

        int balance = 0;
        int longest = 0;

        for (int i = 0; i < nums.size(); i++) {
            balance += (nums[i] == 0) ? -1 : 1;

            if (first.count(balance)) {
                longest = max(longest, i - first[balance]);
            } else {
                first[balance] = i;
            }
        }

        return longest;
    }
};