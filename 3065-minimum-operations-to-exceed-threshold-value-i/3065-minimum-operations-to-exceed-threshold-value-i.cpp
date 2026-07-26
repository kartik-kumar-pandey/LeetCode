class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       int ret=0;
       priority_queue<int,vector<int>,greater<int>>pq;
       for(int num:nums){
        pq.push(num);
       }
       while(!pq.empty() && pq.top()<k){
        pq.pop();
        ret++;
       }

       return ret;
    }
};