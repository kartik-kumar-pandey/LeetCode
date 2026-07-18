class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small=INT_MAX,large=INT_MIN;
        for(int i:nums){
            large=max(large,i);
            small=min(small,i);
        }

        return gcd(small,large);
    }
};