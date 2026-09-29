class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        for (char ch : t) {
            need[ch]++;
        }

        int missing = t.size();
        int left = 0;
        int bestStart = 0;
        int bestLength = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (need[s[right]] > 0) {
                missing--;
            }

            need[s[right]]--;

            while (missing == 0) {
                int length = right - left + 1;

                if (length < bestLength) {
                    bestLength = length;
                    bestStart = left;
                }

                need[s[left]]++;

                if (need[s[left]] > 0) {
                    missing++;
                }

                left++;
            }
        }

        if (bestLength == INT_MAX) {
            return "";
        }

        return s.substr(bestStart, bestLength);
    }
};
