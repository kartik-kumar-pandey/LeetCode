class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max=nums[n-1];
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==max){
                cnt++;
            }
        }
        bool seq=true;
        for(int i=0;i<n-1;i++){
            if((i+1) != nums[i]){
                seq=false;
            }
        }
        bool flag=(max+1==n);
        bool count=(cnt==2);
        return flag&&count&&seq;
        
    }
};