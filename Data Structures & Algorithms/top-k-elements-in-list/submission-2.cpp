class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<std::pair<int, int> > pq;
        std::unordered_map<int, int> num_to_freq;
        
        for (auto& num : nums)
            num_to_freq[std::move(num)]++;
        
        for (auto& [num, freq] : num_to_freq) 
            pq.push(std::make_pair(std::move(freq), std::move(num)));
        
        std::vector<int> res;
        while (res.size() < k) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
