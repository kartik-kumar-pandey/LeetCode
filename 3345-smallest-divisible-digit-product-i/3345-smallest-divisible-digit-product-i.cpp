class Solution {
public:
    int dig(int n){
        int prod=1;
        while(n){
            int x=n%10;
            prod=prod*x;
            n/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int prod=1;
        int temp=n;
        while(1){
            
            prod=dig(temp);
            if(prod%t==0){
                return temp;
            }else{
                temp++;
            }
        }
        return -1;
    }
};