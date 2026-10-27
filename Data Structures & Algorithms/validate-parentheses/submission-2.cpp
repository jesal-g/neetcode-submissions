class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        std::unordered_map<char, char> memo = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };
        for (char c : s) {
            // found a closing bracket
            if (memo.find(c) != memo.end()) {
                if (st.empty()) return false;
                if (st.top() != memo[c]) {
                    return false;
                }
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
