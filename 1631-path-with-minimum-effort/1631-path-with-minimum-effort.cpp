class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;

        vector<pair<int,int>>directions={
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        while(!pq.empty()){
            pair<int,pair<int,int>>p=pq.top();
            int effort=p.first;
            int r=p.second.first;
            int c=p.second.second;
            pq.pop();

            if(r==n-1 && c==m-1) return effort;

            if(effort>dist[r][c]) continue;

            for(int k=0;k<4;k++){
                int nr=r+directions[k].first;
                int nc=c+directions[k].second;

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEffort=max(effort,abs(heights[r][c]-heights[nr][nc]));

                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};