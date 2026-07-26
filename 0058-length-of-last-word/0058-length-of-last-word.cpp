class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int ret=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ' && n > 0 && ret ==0 ){
                continue;
            }else if(s[i] != ' '){
                ret++;
            }else{
                break;
            }
        }
        return ret;
    }
};