class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int lp = 0;
        int rp = lp + 1;
        int currMax = 0;
        while (rp < prices.size()) {
            if (prices[rp] < prices[lp]) {
                lp = rp;
            }
            currMax = std::max(currMax, prices[rp] - prices[lp]);
            rp++;
        }
        return currMax;
    }
};
