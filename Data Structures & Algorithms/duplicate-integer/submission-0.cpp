class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, bool> seen;
        for (const int& n : nums) {
            if (seen.find(n) == seen.end()) {
                seen[n] = true;
            }
            else {
                return true;
            }
        }
        return false;
    }
};