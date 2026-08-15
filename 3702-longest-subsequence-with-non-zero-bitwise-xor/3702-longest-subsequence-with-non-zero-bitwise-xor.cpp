class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool flag=true;
        for(int i:nums){
            if(i!=0){
                flag=false;
            }
        }
        if(flag){
            return 0;
        }

        int n=nums.size();
        int ret = 0;
        int count = 1;
        for (int i = 0; i < nums.size(); i++) {
            ret ^= nums[i];
        }

        if (ret != 0) {
            return nums.size();
        }
        
        if (n == 1)
            return 0;
        else
            return n - 1;
    }
};