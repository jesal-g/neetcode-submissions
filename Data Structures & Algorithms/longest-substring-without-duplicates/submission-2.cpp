class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> char_set;
        int l = 0;
        int longest_ss {0};
        for (size_t r = 0; r < s.size(); ++r) {
            while (char_set.find(s[r]) != char_set.end()) {
                char_set.erase(s[l]);
                l++;
            }
            char_set.insert(s[r]);
            longest_ss = std::max(longest_ss, static_cast<int>(char_set.size()));
        }
        return longest_ss;
    }
};
