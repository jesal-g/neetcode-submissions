class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> curr_ss_set;
        int l = 0;
        int size = static_cast<int>(s.size());
        int longest_ss_len = 0;
        for (int r = 0; r < size; ++r) {
            while (curr_ss_set.find(s[r]) != curr_ss_set.end()) {
                curr_ss_set.erase(s[l]);
                l++;
            }
            curr_ss_set.insert(s[r]);
            longest_ss_len = std::max(longest_ss_len, static_cast<int>(curr_ss_set.size()));
        }
        return longest_ss_len;
    }
};
