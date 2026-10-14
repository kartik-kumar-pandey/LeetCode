class Solution {
public:
   
    int check_digit(int num){
        int curr=0;
        while(num){
            curr++;
            num/=10;
        }

        return curr;
    }
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num){
            return "";
        }
        
        string ret="";
        
        for(int i=0;i<num;i++){
            int a=min(9,sum);
            ret+=to_string(a);
            sum-=a;
        }

        return ret;
    }
};