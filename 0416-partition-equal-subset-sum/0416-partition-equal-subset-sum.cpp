class Solution {
public:
    bool helper(vector<int>& nums,vector<vector<int>>&dp, int n, int target){
        if(target==0){
            return true;
        }
        if(n==0){
            return (nums[0]==target);
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }

        bool nottake=helper(nums,dp,n-1,target);
        bool take=false;

        if(target>=nums[n]){
            take=helper(nums,dp,n-1,target-nums[n]);
        }

        return dp[n][target]=(take||nottake);
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(nums,dp,n-1,target);
    }
};