class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long sum = 0;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(nums[i]<=sum){
                sum+=nums[i];
            }else{
                sum=nums[i];
            } 
        }
        return sum;
    }
};