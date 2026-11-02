class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();

        int len=INT_MAX;
        
        for(int i=0;i<n;i++){
            int curr_or=0;
            for(int j=i;j<n;j++){
                curr_or|=nums[j];
                if(curr_or>=k){
                    
                    len=min(len,j-i+1);
                }
                
            }
        }
        if(len==INT_MAX){
            return -1;
        }
        return len;
    }
};