class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ret=0;
        int n=s.size();
        int last=-1;

        for(int i=0;i<n;i++){
            if(i>=2 && s[i-2]=='a' && s[i-1]=='b' && s[i]=='c'){
                last=i-2;
            }

            ret+=i-last;
        }

        return ret;
    }
};