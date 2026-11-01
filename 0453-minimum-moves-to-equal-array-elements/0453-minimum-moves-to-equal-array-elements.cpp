class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min=INT_MAX;
        for(int i:nums){
            if(i<min){
                min=i;
            }
        }
        int ret=0;
        for(int i:nums){
            ret+=(i-min);
        }
        return ret;
    }
};