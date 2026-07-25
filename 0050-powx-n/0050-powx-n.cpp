class Solution {
public:
    double myPow(double x, int n) {
        long num = n;
        if(num<0){
            x=1/x;
            num=-num;
        }
        double ret=1;
        while(num){
            if(num&1){
                ret*=x;
            }
            x*=x;
            num>>=1;
        }

        return ret;
    }
};