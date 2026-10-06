class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        std::unordered_map<char, int> sMap;
        for (int i = 0; i < s.length(); ++i) {
            if (sMap.find(s[i]) != sMap.end()) {
                sMap[s[i]]++;
            }
            else {
                sMap[s[i]] = 1;
            }
        }

        for (int i = 0; i < t.length(); ++i) {
            if (sMap.find(t[i]) != sMap.end()) {
                sMap[t[i]]--;
                if (sMap[t[i]] == 0) {
                    sMap.erase(t[i]);
                }
            }
            else {
                return false;
            }
        }

        return sMap.empty();
    }
};
