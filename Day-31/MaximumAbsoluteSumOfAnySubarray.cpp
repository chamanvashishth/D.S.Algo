class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;
        int answer = 0;

        for (int num : nums) {
            maxSum = max(0, maxSum + num);
            minSum = min(0, minSum + num);

            answer = max(answer, max(maxSum, -minSum));
        }

        return answer;
    }
};