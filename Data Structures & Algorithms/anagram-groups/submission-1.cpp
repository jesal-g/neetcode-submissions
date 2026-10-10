class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string> > sorted_to_anagrams;
        for (auto& str : strs) {
            std::string original_str = str;
            std::sort(str.begin(), str.end());
            sorted_to_anagrams[str].push_back(original_str);
        }

        std::vector<std::vector<std::string> > res;
        for (auto& [k, anagrams] : sorted_to_anagrams) {
            res.push_back(std::move(anagrams));
        }

        return res;
    }
};
