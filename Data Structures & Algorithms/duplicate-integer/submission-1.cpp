class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniq_nums;
        for (int& num : nums) {
            size_t before = uniq_nums.size();
            uniq_nums.insert(num);
            if (uniq_nums.size() == before)
                return true;
        }
        return false;
    }
};