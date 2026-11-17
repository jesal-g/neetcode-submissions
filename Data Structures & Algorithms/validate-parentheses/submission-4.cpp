class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        std::unordered_map<char, char> memo = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (auto& c : s) {
            // closing bracket
            if (memo.find(c) != memo.end()) {
                if (st.empty())
                    return false;
                if (memo[c] != st.top())
                    return false;
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
