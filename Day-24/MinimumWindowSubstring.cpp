class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int missing = t.size();

        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char current = s[right];

            if (need[current] > 0) {
                missing--;
            }

            need[current]--;

            // Shrink the window while it contains all required characters.
            while (missing == 0) {
                int windowLength = right - left + 1;

                if (windowLength < minLength) {
                    minLength = windowLength;
                    start = left;
                }

                char leftChar = s[left];
                need[leftChar]++;

                if (need[leftChar] > 0) {
                    missing++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};