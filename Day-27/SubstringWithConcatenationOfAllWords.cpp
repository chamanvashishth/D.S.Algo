class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        if (s.size() < totalLength) {
            return result;
        }

        unordered_map<string, int> required;

        for (string& word : words) {
            required[word]++;
        }

        // Try every possible alignment of a word-sized window.
        for (int i = 0; i < wordLength; i++) {
            int left = i;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = i; right + wordLength <= s.size();
                 right += wordLength) {

                string current = s.substr(right, wordLength);

                // Reset the window when the word is not required.
                if (required.find(current) == required.end()) {
                    window.clear();
                    count = 0;
                    left = right + wordLength;
                    continue;
                }

                window[current]++;
                count++;

                // Remove extra occurrences from the left.
                while (window[current] > required[current]) {
                    string leftWord = s.substr(left, wordLength);
                    window[leftWord]--;
                    left += wordLength;
                    count--;
                }

                // The current window contains all words exactly as needed.
                if (count == wordCount) {
                    result.push_back(left);

                    string leftWord = s.substr(left, wordLength);
                    window[leftWord]--;
                    left += wordLength;
                    count--;
                }
            }
        }

        return result;
    }
};