class Solution {
public:
    int nextIndex(vector<int>& nums, int index) {
        int n = nums.size();

        int next = (index + nums[index]) % n;

        if (next < 0) {
            next += n;
        }

        return next;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int slow = i;
            int fast = i;

            bool forward = nums[i] > 0;

            while (true) {
                if ((nums[slow] > 0) != forward) {
                    break;
                }

                slow = nextIndex(nums, slow);

                if ((nums[fast] > 0) != forward) {
                    break;
                }

                fast = nextIndex(nums, fast);

                if ((nums[fast] > 0) != forward) {
                    break;
                }

                fast = nextIndex(nums, fast);

                if (slow == fast) {
                    if (slow == nextIndex(nums, slow)) {
                        break;
                    }

                    return true;
                }
            }
        }

        return false;
    }
};