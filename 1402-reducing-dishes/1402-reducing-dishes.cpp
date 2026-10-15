
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();

        vector<vector<int>>dp(n+1,vector<int>(n+2,0));

        for(int i=n-1;i>=0;i--){
            for(int t=n;t>=1;t--){
                int pick=satisfaction[i]*t +dp[i+1][t+1];
                int unpick=dp[i+1][t];
                dp[i][t]=max(pick,unpick);
            }
        }

        return dp[0][1];
    }
};
