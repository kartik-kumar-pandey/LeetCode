class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& curr, vector<bool>& used) {

        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        set<int>st;

        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) {
                continue;
            }
            if(st.count(nums[i])){
                continue;
            }
            st.insert(nums[i]);

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, curr, used);

            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>curr;
        vector<bool> used(nums.size(),false);
        solve(nums,curr,used);

        return ans;

    }
};