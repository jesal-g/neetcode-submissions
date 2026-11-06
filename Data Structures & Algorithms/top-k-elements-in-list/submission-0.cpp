class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqs;
        for (auto& num : nums) {
            freqs[num]++;
        }

        std::priority_queue<std::pair<int, int> > pq;
        for (auto&[num, freq] : freqs) {
            pq.push(std::make_pair(freq, num));
        }

        std::vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;

        
    }
};
