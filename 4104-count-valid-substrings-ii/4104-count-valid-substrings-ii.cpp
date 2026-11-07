class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ret=0;
        int n=s.size();
        int a=-1,b=-1,c=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='a') a=i;
            if(s[i]=='b' && a!=-1) b=a;
            if(s[i]=='c' && b!=-1) c=b;

            ret+=i-c;
        }

        return ret;
    }
};