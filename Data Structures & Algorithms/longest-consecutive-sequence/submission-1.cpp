class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int curr_longest = 0;
        std::unordered_set<int> nums_set{nums.begin(), nums.end()};
        for (auto& num : nums_set) {
            // num has no next neighbor --> end of seq
            if (nums_set.find(num+1) == nums_set.end()) {
                int curr_len = 1;
                int next_num = num - 1;
                while (nums_set.find(next_num) != nums_set.end()) {
                    curr_len++;
                    next_num--;
                }
                curr_longest = std::max(curr_longest, curr_len);
            }
        }
        return curr_longest;
    }
};
