class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set_nums{nums.begin(), nums.end()};
        int longest_seq = 0;
        for (int& num : nums) {
            // if num has no right neighbor -> end of a seq
            if (set_nums.find(num+1) == set_nums.end()) {
                // check chain of left neighbors
                int curr_len = 1;
                int l_index = num - 1;
                while (set_nums.find(l_index) != set_nums.end()) {
                    l_index--;
                    curr_len++;
                }
                longest_seq = std::max(curr_len, longest_seq);
            }
        }
        return longest_seq;
    }
};
