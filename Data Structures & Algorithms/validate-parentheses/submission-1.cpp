class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> memo = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        std::stack<char> st;

        for (char& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else if (memo.find(c) != memo.end()) {
                if (!st.empty() && st.top() == memo[c]) {
                    st.pop();
                }
                else {
                    st.push(c);
                }
            }
            else {
                return false;
            }
        }

        return st.empty();
    }
};
