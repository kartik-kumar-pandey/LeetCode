class Solution {
public:
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& curr,
             vector<vector<int>>& ans) {

        // Base case
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (idx == candidates.size() || candidates[idx] > target)
            return;

        // ---------------- PICK ----------------
        curr.push_back(candidates[idx]);

        dfs(candidates, target - candidates[idx], idx + 1, curr, ans);

        // ---------------- UNPICK ----------------
        curr.pop_back();

        // Skip duplicates for the UNPICK branch
        int next = idx + 1;

        while (next < candidates.size() &&
               candidates[next] == candidates[idx]) {
            next++;
        }

        dfs(candidates, target, next, curr, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        dfs(candidates, target, 0, curr, ans);

        return ans;
    }
};