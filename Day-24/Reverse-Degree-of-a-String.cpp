class Solution {
public:
    int reverseDegree(string s) {
        int answer = 0;

        for (int i = 0; i < s.size(); i++) {
            int value = 'z' - s[i] + 1;
            answer += value * (i + 1);
        }

        return answer;
    }
};
