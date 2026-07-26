class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=nums[0];
        int ret=nums[0];

        for(int i=1;i<nums.size();i++){
            curr_sum=max(nums[i],nums[i]+curr_sum);
            ret=max(ret,curr_sum);
        }

        return ret;
    }
};