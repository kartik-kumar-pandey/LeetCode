class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>v(n+1,0);
        for(int i=0;i<bookings.size();i++){
            int a=bookings[i][0];
            int b=bookings[i][1];
            int val=bookings[i][2];
            v[a-1]+=val;
            v[b]-=val;
        }
        for(int i=1;i<n;i++)
        {
            v[i]=v[i-1]+v[i];

        }
        v.pop_back();
        

        return v;
    }
};