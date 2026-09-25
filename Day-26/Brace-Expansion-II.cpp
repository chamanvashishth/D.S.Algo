class Solution {
public:
    set<string> parse(string& s, int& i) {
        set<string> result = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> part;

            if (s[i] == '{') {
                i++;
                part = parse(s, i);
                i++; // skip '}'
            } else {
                part.insert(string(1, s[i]));
                i++;
            }

            set<string> next;

            for (const string& a : result) {
                for (const string& b : part) {
                    next.insert(a + b);
                }
            }

            result = next;
        }

        return result;
    }

    set<string> parseExpression(string& s, int& i) {
        set<string> result;

        while (i < s.size() && s[i] != '}') {
            set<string> part = parse(s, i);

            result.insert(part.begin(), part.end());

            if (i < s.size() && s[i] == ',') {
                i++;
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> words = parseExpression(expression, i);

        return vector<string>(words.begin(), words.end());
    }
};
