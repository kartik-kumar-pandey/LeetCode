class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int o_sum=0,e_sum=0;
        for(int i=1;i<=2*n;i++){
            if(i%2!=0){
                o_sum+=i;
            }else{
                e_sum+=i;
            }
        }

        return gcd(o_sum,e_sum);
    }
};