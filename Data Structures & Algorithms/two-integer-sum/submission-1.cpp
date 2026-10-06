class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> diffs;
        for (int i = 0; i < nums.size(); ++i) {
            diffs[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            const int match = target-nums[i];
            if (diffs.find(match) != diffs.end() && i != diffs[match]) {
                return {std::min(diffs[match], i), std::max(diffs[match], i)};
            }
        } 
    }
};
