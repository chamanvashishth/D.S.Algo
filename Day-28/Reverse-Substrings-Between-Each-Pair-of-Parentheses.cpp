class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stack;
        stack.push_back("");

        for (char ch : s) {
            if (ch == '(') {
                stack.push_back("");
            } else if (ch == ')') {
                reverse(stack.back().begin(), stack.back().end());

                string current = stack.back();
                stack.pop_back();

                stack.back() += current;
            } else {
                stack.back() += ch;
            }
        }

        return stack.back();
    }
};
