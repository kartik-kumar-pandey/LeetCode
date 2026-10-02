class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ret(n,-1);
        stack<int> s;

        for(int i=0;i<2*n;i++){
            int idx=i%n;
            int curr=nums[idx];
            while(!s.empty() && nums[s.top()]<nums[idx]){
                ret[s.top()]=nums[idx];
                s.pop();
                
            }
            if(i<n){
                s.push(idx);
            }
        }
        return ret;
        
    }
};