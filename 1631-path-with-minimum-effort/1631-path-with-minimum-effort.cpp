class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        queue<pair<int,int>>q;
        q.push({0,0});
        dist[0][0]=0;

        vector<pair<int, int>> directions = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        while(!q.empty()){
            pair<int,int>p=q.front();
            int r=p.first;
            int c=p.second;
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+directions[k].first;
                int nc=c+directions[k].second;

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int effort=max(dist[r][c],abs(heights[r][c]-heights[nr][nc]));

                    if(effort<dist[nr][nc]){
                        dist[nr][nc]=effort;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};