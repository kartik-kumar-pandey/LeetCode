class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());

        int target=nums[n/2];
        int ret=0;
        for(int i=0;i<n;i++){
            ret+=abs(target-nums[i]);
        }

        return ret;
    }
};