// class Solution {
// public:
//     int recc(int i,int j ,vector<int> &dp){
//         if(i==0 && j==0)
//         return 1;
//         if(i<0 ||j<0){
//             return 0;
//         }
//         int up=recc(i-1,j,dp);
//         int down=recc(i,j-1,dp);

//         return up+down;


//     }
//     int uniquePaths(int m, int n) {
//         vector<int>dp(m,vector<int>(n));
//         dp[0][0]=1;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 dp[i][j]+=dp[i-1][j-1];
//             }
//         }

//     }
// };


class Solution {
public:


    int uniquePaths(int m, int n) {
        vector<int>dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};