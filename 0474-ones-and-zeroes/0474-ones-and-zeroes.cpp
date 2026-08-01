class Solution {
public:
//     int dp[601][101][101];

//     int solve(vector<string>& strs, int m ,int n, int idx){
//         if(idx==strs.size()){
//             return 0;
//         }

//         if(dp[idx][m][n]!=-1){
//             return dp[idx][m][n];
//         }

//         string curr=strs[idx];
//         int ones=0,zeros=0;
//         for(int i=0;i<curr.size();i++){
//             if(curr[i]=='0'){
//                 zeros++;
//             }else{
//                 ones++;
//             }
//         }

//         int ans = solve(strs, m, n, idx + 1);

//         if(m>=zeros && n>=ones){
//             int pick=1+solve(strs,m-zeros,n-ones,idx+1);
//             ans=max(ans,pick);
//         }

//         return dp[idx][m][n]=ans;
//     }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int idx=0;idx<strs.size();idx++){
            int zeros=0,ones=0;
            string curr=strs[idx];
            for(int k=0;k<curr.size();k++){
                if(curr[k]=='0'){
                    zeros++;
                }else{
                    ones++;
                }
            }

            for(int i=m;i>=zeros;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j]=max(dp[i][j],1+dp[i-zeros][j-ones]);
                }
            }

        }
        return dp[m][n];
    }
};