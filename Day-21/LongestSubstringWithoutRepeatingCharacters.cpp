class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            char current = s[right];

            // Move the window past the previous occurrence
            // only if that occurrence is inside the current window.
            if (lastSeen.count(current) && lastSeen[current] >= left) {
                left = lastSeen[current] + 1;
            }

            lastSeen[current] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};