class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>right_min(n),left_max(n);
        left_max[0]=nums[0];
        for(int i=1;i<n;i++){
            left_max[i]=max(left_max[i-1],nums[i]);
        }



        right_min[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            right_min[i]=min(right_min[i+1],nums[i]);
        }
        
        for(int i=0;i<n;i++){
            if((left_max[i]-right_min[i])<=k){
                return i;
            }
        }

        return -1;
    }
};