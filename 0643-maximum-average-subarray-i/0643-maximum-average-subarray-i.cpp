class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ret;
        int n=nums.size();
        // unordered_map<int,int>mp;
        
        double curr;
        for(int i=0;i<k;i++){
            curr+=nums[i];
           
        }
        ret=curr/k;
        if(k==n){
            return ret;
        }
        
        for(int i=k;i<n;i++){
            double curr_avg;
            curr=curr-nums[i-k];
            curr+=nums[i];
            curr_avg=curr/k;
            ret=max(ret,curr_avg);
            
        }
        return ret;
    }
};