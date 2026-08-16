class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int ret=-1;
        int mindist=INT_MAX;
        int a1=target[0],b1=target[1];

        for(int i=0;i<n;i++){
            int a=drones[i][0];
            int b=drones[i][1];
            int range=drones[i][2];

            int dist=(abs(a-a1)+abs(b-b1));

            if(dist<=range && dist<mindist){
                mindist=dist;
                ret=i;
            }

           
        }

        return ret;
    }
};