class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ret(num_people,0);
        int start=1;
        int i=0;
        while(candies>0){
            int x=min(start,candies);
            candies-=x;
            ret[(i%num_people)]+=x;
            start++;
            i++;
        }

        return ret;
    }
};