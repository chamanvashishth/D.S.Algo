/**
 * LeetCode 26: Remove Duplicates from Sorted Array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        // nums[0] is always unique because the array is non-empty.
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};