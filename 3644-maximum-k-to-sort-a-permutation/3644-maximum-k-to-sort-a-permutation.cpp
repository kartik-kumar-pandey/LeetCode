class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int ret=-1;

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                if(ret==-1)
                    ret=nums[i];
                else
                    ret&=nums[i];
            }
        }

        if(ret==-1){
            return 0;
        }
        return ret;
    }
};