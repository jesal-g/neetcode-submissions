class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string> > sorted_to_sublist;
        for (auto& str : strs) {
            std::string sorted = str;
            std::sort(sorted.begin(), sorted.end());
            sorted_to_sublist[sorted].push_back(std::move(str));
        }
        std::vector<std::vector<std::string> > res;
        for (auto& [key, sublist] : sorted_to_sublist) {
            res.push_back(std::move(sublist));
        }
        return res;
    }
};
