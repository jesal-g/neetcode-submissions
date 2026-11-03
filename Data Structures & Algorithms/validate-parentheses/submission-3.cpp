class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> memo {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        std::stack<char> st;
        for (char& c : s) {
            // closing brace
            if (memo.find(c) != memo.end()) {
                if (st.empty()) return false; // no corresponding opening
                if (memo[c] == st.top()) {
                    st.pop();
                } else {
                    return false;
                }
            } 
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
