class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> ss_chars;
        int longest = 0;
        int l = 0;
        int r = l;
        while (r < static_cast<int>(s.size())) {
            while (ss_chars.find(s[r]) != ss_chars.end()) {
                ss_chars.erase(s[l]);
                l++;
            }
            ss_chars.insert(s[r]);
            longest = std::max(longest, static_cast<int>(ss_chars.size()));
            r++;
        }
        return longest;
    }
};
