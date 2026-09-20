class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int ret=0;
        for(int i=0;i<n;i++){
            int idx=26-abs('a'-s[i]);
            ret+=((i+1)*idx);
        }
        return ret;
    }
};