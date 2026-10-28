class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) {
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);

        // Count characters in s1 and the first window of s2.
        for (int i = 0; i < n; i++) {
            s1Count[s1[i] - 'a']++;
            windowCount[s2[i] - 'a']++;
        }

        if (s1Count == windowCount) {
            return true;
        }

        // Slide the fixed-size window across s2.
        for (int right = n; right < m; right++) {
            windowCount[s2[right] - 'a']++;
            windowCount[s2[right - n] - 'a']--;

            if (s1Count == windowCount) {
                return true;
            }
        }

        return false;
    }
};