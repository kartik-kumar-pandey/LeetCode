class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ret;
        int min=INT_MAX;
        int max=INT_MIN;
        for(int i:nums){
            if(i>max){
                max=i;
            }
            if(i<min){
                min=i;
            }
        }
        unordered_set<int>s(nums.begin(),nums.end());
        for(int i=min;i<=max;i++){
            if(s.count(i)){
                continue;
            }else{
                ret.push_back(i);
            }
        }
       return ret; 
    }
};