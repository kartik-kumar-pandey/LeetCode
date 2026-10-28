class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    void dfs(vector<vector<int>>&grid,int i,int j,int n,queue<pair<int,int>>&q){
       if(i<0 || j<0 || i>=n || j>=n || grid[i][j] != 1){
            return;
        }
        grid[i][j]=2;
        q.push({i,j});
        for(int k=0;k<4;k++){
            int nr=dr[k]+i;
            int nc=dc[k]+j;
            dfs(grid,nr,nc,n,q);
        }
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        queue<pair<int,int>>q;
 
        bool flag=false;
        for(int i=0;i<n;i++){
            if(flag==true) break;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    flag=true;
                    dfs(grid,i,j,n,q);
                    break;
                }
            }
        }
        while(q.size()){
            int sz=q.size();
            while(sz){
                auto [a,b]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=dr[i]+a;
                    int nc=dc[i]+b;
                   if (nr < 0 || nc < 0 || nr >= n || nc >= n ||grid[nr][nc] == 2) {
                        continue;
                    }
                    if(grid[nr][nc]==1){
                        return ans;
                    }
                    q.push({nr,nc});
                    grid[nr][nc]=2;
                }
                sz--;
                
            }
            ans++;
        }
        return ans;
    }
};