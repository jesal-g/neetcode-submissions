class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        std::unordered_map<char, int> freqs;
        for (char& c : s) {
            freqs[c]++; //default val is 0, gets incremented
        }
        for (char& c : t) {
            if (freqs.find(c) == freqs.end())
                return false;
            if ((--freqs[c]) == 0) {
                freqs.erase(c);
            }
        }
        return freqs.empty();
    }
};
