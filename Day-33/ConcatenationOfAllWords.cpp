class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        if (words.empty()) {
            return answer;
        }

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) {
            return answer;
        }

        unordered_map<string, int> need;
        for (const string& word : words) {
            need[word]++;
        }

        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string, int> window;
            int left = offset;
            int count = 0;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (!need.count(word)) {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                window[word]++;
                count++;

                while (window[word] > need[word]) {
                    string first = s.substr(left, wordLen);
                    window[first]--;
                    count--;
                    left += wordLen;
                }

                if (count == wordCount) {
                    answer.push_back(left);

                    string first = s.substr(left, wordLen);
                    window[first]--;
                    count--;
                    left += wordLen;
                }
            }
        }

        return answer;
    }
};