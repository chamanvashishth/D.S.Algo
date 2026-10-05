/**
 * LeetCode 977: Squares of a Sorted Array
 * https://leetcode.com/problems/squares-of-a-sorted-array/
 *
 * Time: O(n)
 * Space: O(n) for the result array
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0;
        int right = n - 1;
        int position = n - 1;

        // The biggest square will always come from one of the two ends.
        // Fill the result from right to left so it stays sorted.
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[position] = leftSquare;
                left++;
            } else {
                result[position] = rightSquare;
                right--;
            }

            position--;
        }

        return result;
    }
};
