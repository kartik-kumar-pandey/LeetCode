class Solution {
public:
    int maxPower(string s) {
        int ret=1;
        int n=s.size();
        int curr=1;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                curr=1;
            }else{
                curr++;
                
            }
            ret=max(ret,curr);
        }

        return ret;
    }
};