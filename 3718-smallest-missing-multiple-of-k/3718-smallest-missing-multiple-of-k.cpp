class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int j=1;
        bool flag=false;

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==k*j){
                j++;
            }

        }
        return k*j;
        
    }
};