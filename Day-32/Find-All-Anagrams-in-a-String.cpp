class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        vector<int> answer;

        for (char ch : p) {
            need[ch - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            window[s[right] - 'a']++;

            if (right - left + 1 > p.size()) {
                window[s[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == p.size() && window == need) {
                answer.push_back(left);
            }
        }

        return answer;
    }
};
