class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
            int idx=nums[i]-1;

            if(nums[i]!=nums[idx]){
                swap(nums[i],nums[idx]);
            }else{
                i++;
            }
        }
        vector<int>ret;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1!=i){
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};