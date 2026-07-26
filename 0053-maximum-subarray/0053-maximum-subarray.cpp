class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ret=INT_MIN;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            ret=max(ret,sum);

            if(sum<0){
                sum=0;
            }
        }

        return ret;
    }
};