class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int size = static_cast<int>(prices.size());
        int max_profit = 0;
        for (int r = 0; r < size; ++r) {
            if (prices[r] < prices[l]){
                l = r;
            }
            max_profit = std::max(max_profit, prices[r] - prices[l]);
        }
        return max_profit;
    }
};
