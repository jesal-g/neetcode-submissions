class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, size_t> seen;
        for (size_t i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (seen.find(diff) != seen.end()) {
                return {
                    static_cast<int>(seen[diff]),
                    static_cast<int>(i)
                };
            }
            seen[nums[i]] = i; 
        }
        return {0,0};
    }
};
