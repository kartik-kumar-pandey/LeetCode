class Solution {
public:
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