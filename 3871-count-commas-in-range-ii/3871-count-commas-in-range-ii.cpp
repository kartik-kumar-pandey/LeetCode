class Solution {
public:
    long long countCommas(long long n) {
        long long ret=0;
        for(long long i=1000;i<=n;i*=1000){
            ret+=1;
            ret+=(n-i);
        }
        return ret;
    }
};