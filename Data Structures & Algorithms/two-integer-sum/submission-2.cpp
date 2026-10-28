class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, size_t> num_to_index;
        for (size_t i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (num_to_index.find(diff) != num_to_index.end()) {
                return {static_cast<int>(num_to_index[diff]), static_cast<int>(i)};
            }
            num_to_index[nums[i]] = i;
        }
        return {0};
    }
};
