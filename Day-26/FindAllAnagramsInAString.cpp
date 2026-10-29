class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int n = s.size();
        int k = p.size();

        if (k > n) {
            return result;
        }

        vector<int> pCount(26, 0);
        vector<int> windowCount(26, 0);

        // Count characters in p and the first window of s.
        for (int i = 0; i < k; i++) {
            pCount[p[i] - 'a']++;
            windowCount[s[i] - 'a']++;
        }

        if (pCount == windowCount) {
            result.push_back(0);
        }

        // Slide the window across s.
        for (int right = k; right < n; right++) {
            windowCount[s[right] - 'a']++;
            windowCount[s[right - k] - 'a']--;

            if (pCount == windowCount) {
                result.push_back(right - k + 1);
            }
        }

        return result;
    }
};