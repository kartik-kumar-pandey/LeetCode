class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());

        // for(int i:nums){
        //     cout<<i;
        // }

        int n=nums.size();
        int i=n-2;

        while(i>=0 && nums[i]>=nums[i+1]){
            i--;

        }
        int idx=0;
        if(i>=0){
            int j=n-1;
            while(nums[j]<=nums[i]){
                j--;

            }
            swap(nums[i],nums[j]);
            idx=j;
        }

        reverse(nums.begin()+(i+1), nums.end());




    }
};