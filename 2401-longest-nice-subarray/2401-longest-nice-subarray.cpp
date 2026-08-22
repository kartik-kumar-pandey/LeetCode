class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask=0;
        int left=0;
        int ret=0;
        
        int n=nums.size();

        for(int right=0;right<n;right++){
            while((mask&nums[right])!=0){
                mask^=nums[left];
                left++;
            }
            mask|=nums[right];
            ret=max(ret,right-left+1);

        }

        return ret;
    }
};