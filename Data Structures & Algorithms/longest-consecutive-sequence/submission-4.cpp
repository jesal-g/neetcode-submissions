class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> nums_set(nums.begin(), nums.end());
        int lcs = nums_set.empty() ? 0 : 1;
        for (auto& num : nums_set) {
            // num has no right neighbors -> end of seq
            if (nums_set.find(num + 1) == nums_set.end()) {
                if (nums_set.find(num - 1) == nums_set.end()) continue;
                // backtrack from num and count seq len
                int curr_lcs = 2;
                while (nums_set.find(num - curr_lcs) != nums_set.end()) {
                    curr_lcs++;
                }
                lcs = std::max(lcs, curr_lcs);
            }
        }
        return lcs;
    }
};
