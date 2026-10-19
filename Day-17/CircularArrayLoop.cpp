class Solution {
private:
    int nextIndex(vector<int>& nums, int index) {
        int n = nums.size();
        return ((index + nums[index]) % n + n) % n;
    }

    bool hasSameDirection(vector<int>& nums, int index, bool forward) {
        return (nums[index] > 0) == forward;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool forward = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {
                // Move slow pointer one step
                int nextSlow = nextIndex(nums, slow);

                if (!hasSameDirection(nums, nextSlow, forward) ||
                    nextSlow == slow) {
                    break;
                }

                slow = nextSlow;

                // Move fast pointer two steps
                int nextFast = nextIndex(nums, fast);

                if (!hasSameDirection(nums, nextFast, forward) ||
                    nextFast == fast) {
                    break;
                }

                int nextFastAgain = nextIndex(nums, nextFast);

                if (!hasSameDirection(nums, nextFastAgain, forward) ||
                    nextFastAgain == nextFast) {
                    break;
                }

                fast = nextFastAgain;

                if (slow == fast) {
                    return true;
                }
            }

            // Mark the traversed path so it is not checked again
            int current = i;

            while (hasSameDirection(nums, current, forward)) {
                int next = nextIndex(nums, current);

                if (next == current) {
                    break;
                }

                nums[current] = 0;
                current = next;
            }
        }

        return false;
    }
};
