class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int current = nums[i];

            if (current < 0) {
                swap(maxProduct, minProduct);
            }

            maxProduct = max(current, maxProduct * current);
            minProduct = min(current, minProduct * current);

            answer = max(answer, maxProduct);
        }

        return answer;
    }
};