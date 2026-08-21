class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>st;

        int n=nums.size();

        for(int i=0;i<n;i++){
            if(!st.empty()&&st.top()==nums[i]){
                st.pop();
                st.push(2*nums[i]);

            }else{
                st.push(nums[i]);
            }
        }

        vector<long long>ret;
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(),ret.end());

        return ret;
    }
};