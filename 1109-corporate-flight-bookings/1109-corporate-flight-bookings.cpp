class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>v(n,0);
        for(int i=0;i<bookings.size();i++){
            int a=bookings[i][0];
            int b=bookings[i][1];
            int val=bookings[i][2];

            for(int j=a;j<=b;j++){
                v[j-1]+=val;
            }
        }

        return v;
    }
};