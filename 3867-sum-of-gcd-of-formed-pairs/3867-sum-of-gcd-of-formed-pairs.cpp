class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref_max(n);
        pref_max[0]=nums[0];
        for(int i=1;i<n;i++){
            pref_max[i]=max(pref_max[i-1],nums[i]);
        }
        vector<int>gcd_nums(n);
        for(int i=0;i<n;i++){
            gcd_nums[i]=gcd(pref_max[i],nums[i]);
        }
        sort(gcd_nums.begin(),gcd_nums.end());

        int times=n/2;
        int low=0,high=n-1;
        long long ret=0;
        while(times--){
            ret+=gcd(gcd_nums[low++],gcd_nums[high--]);
        }
        return ret;
    }
};