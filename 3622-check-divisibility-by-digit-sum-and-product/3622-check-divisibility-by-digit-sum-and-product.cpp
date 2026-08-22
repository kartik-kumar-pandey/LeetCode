class Solution {
public:
    bool checkDivisibility(int m) {
        int digit_sum=0;
        int product_sum=1;
        int n=m;
        while(n){
            int digit=n%10;
            digit_sum+=digit;
            product_sum*=digit;

            n/=10;
        }

        return m%(digit_sum+product_sum)==0;
    }
};