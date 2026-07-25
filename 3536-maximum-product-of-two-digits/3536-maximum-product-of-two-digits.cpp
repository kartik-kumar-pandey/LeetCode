class Solution {
public:
    int maxProduct(int n) {
        int m1=-1,m2=-1;
        while(n){
            int curr=n%10;
            if(curr>m1){
                m2=m1;
                m1=curr;
            }else if(curr>m2){
                m2=curr;
            }
            n/=10;
        }
        return m1*m2;
    }
};