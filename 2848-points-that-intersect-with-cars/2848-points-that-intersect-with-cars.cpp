class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>v(100,0);
        for(int i=0;i<nums.size();i++){
            int s=nums[i][0];
            int e=nums[i][1];
            for(int j=s;j<=e;j++){
                if(v[j-1]==0)
                v[j-1]++;
            }
        }
        int ret=0;
        for(int i:v){
            if(i==1){
                ret++;
            }
        }
        return ret;
    }
};