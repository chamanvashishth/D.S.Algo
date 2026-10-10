class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int current = 0;
        int right = nums.size() - 1;

        while (current <= right) {
            if (nums[current] == 0) {
                swap(nums[left], nums[current]);
                left++;
                current++;
            } else if (nums[current] == 1) {
                current++;
            } else {
                swap(nums[current], nums[right]);
                right--;
            }
        }
    }
};