class Solution {
public:
    int dp[601][101][101];

    int solve(vector<string>& strs, int m ,int n, int idx){
        if(idx==strs.size()){
            return 0;
        }

        if(dp[idx][m][n]!=-1){
            return dp[idx][m][n];
        }

        string curr=strs[idx];
        int ones=0,zeros=0;
        for(int i=0;i<curr.size();i++){
            if(curr[i]=='0'){
                zeros++;
            }else{
                ones++;
            }
        }

        int ans = solve(strs, m, n, idx + 1);

        if(m>=zeros && n>=ones){
            int pick=1+solve(strs,m-zeros,n-ones,idx+1);
            ans=max(ans,pick);
        }

        return dp[idx][m][n]=ans;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,0);
    }
};