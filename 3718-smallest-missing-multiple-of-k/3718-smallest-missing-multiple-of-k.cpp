class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());
        int mul=1;
        bool flag=false;
        if(nums.size()==1){
            if(nums[0]==k){
                return k*2;
            }else{
                return k;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(!s.count(mul*k)){

                return mul*k;
            }else{
                flag=true;
            }
            mul++;
        }
        if(flag){
            return k*(nums.size()+1);
        }
        
        return 0;
    }
};