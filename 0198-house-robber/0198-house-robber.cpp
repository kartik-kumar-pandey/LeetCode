class Solution {
public:
    int rec(vector<int>& nums, vector<int>& dp, int i) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int pick=nums[i] + rec(nums, dp, i+2);
        int unpick=rec(nums, dp, i+1);
        return dp[i] = max(unpick,pick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return rec(nums, dp, 0);
    }
    
};