class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for (const auto& entry : mp) {
            pq.push({entry.second, entry.first});
        }
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};
