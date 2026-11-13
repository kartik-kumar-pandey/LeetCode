class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        int temp=num;
        while(temp){
            int rem=temp%10;
            v.push_back(rem);
            temp=temp/10;
        }
        sort(v.begin(),v.end());
        int min1=v[0];
        int min2=v[1];
        int max1=v[2];
        int max2=v[3];

        int sum=max1+10*min1;
        sum+=max2+10*min2;

        return sum; 
        
    }
};