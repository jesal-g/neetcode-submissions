class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string> > sortedStrToAnagrams;

        for (const auto& str : strs) {
            std::string sorted_str = str;
            std::sort(sorted_str.begin(), sorted_str.end());
            sortedStrToAnagrams[sorted_str].push_back(std::move(str));
        }

        std::vector<std::vector<std::string> > res;

        for (const auto&[sorted_str, anagrams] : sortedStrToAnagrams) {
            res.push_back(std::move(anagrams));
        }

        return res;
    }
};
