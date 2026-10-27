class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t lp = 0;
        size_t rp = lp + 1;

        int max_profit = 0;
        while (rp < prices.size()) {
            int curr_profit = prices[rp] - prices[lp];
            max_profit = std::max(max_profit, curr_profit);
            if (prices[rp] < prices[lp]) {
                lp = rp;
            }
            rp++;
        }
        return max_profit;
    }
};
