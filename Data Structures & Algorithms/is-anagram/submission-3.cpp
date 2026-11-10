class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        std::unordered_map<char, int> uniq;
        for (auto& c : s)
            uniq[c]++;
        
        for (auto& c : t) {
            if (uniq.find(c) == uniq.end()) {
                return false;
            }
            if ((--uniq[c]) == 0) {
                uniq.erase(c);
            }
        }
        return uniq.empty();
    }
};
