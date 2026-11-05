class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ret=0;
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==1){
                ret+=it->first;
            }
        }
        return ret;
    }
};