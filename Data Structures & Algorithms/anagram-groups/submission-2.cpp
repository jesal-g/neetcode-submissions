class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string> > sorted_to_anagrams;
        for (auto& str : strs) {
            std::string original = str;
            std::sort(str.begin(), str.end());
            sorted_to_anagrams[str].push_back(original);
        }

        vector<vector<string>> res;
        for (auto& [sorted, anagrams] : sorted_to_anagrams) {
            res.push_back(std::move(anagrams));
        }

        return res;
    }
};
