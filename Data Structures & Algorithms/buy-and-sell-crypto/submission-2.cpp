class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit {0};
        int lowest_curr_price {prices[0]};
        for (auto& price : prices) {
            lowest_curr_price = std::min(lowest_curr_price, price);
            max_profit = std::max(max_profit, price - lowest_curr_price);
        }
        return max_profit;
    }
};
