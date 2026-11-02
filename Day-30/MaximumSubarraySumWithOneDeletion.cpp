class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDeletion = arr[0];
        int oneDeletion = 0;
        int answer = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int current = arr[i];

            oneDeletion = max(noDeletion, oneDeletion + current);
            noDeletion = max(current, noDeletion + current);

            answer = max(answer, max(noDeletion, oneDeletion));
        }

        return answer;
    }
};