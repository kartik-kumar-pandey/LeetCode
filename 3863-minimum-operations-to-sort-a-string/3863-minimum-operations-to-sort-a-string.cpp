class Solution {
public:
    int minOperations(string s) {
        string temp=s;
        sort(temp.begin(),temp.end());
        if(s==temp) return 0;
        
        vector<int>freq(26,0);
        for(auto it:s) freq[it-'a']++;
        
        //edge cases n==1,n==2
        int n=s.size();
        if(n==1) return 0;
        if(n==2) return -1;

        char fs=s[0];
        char ls=s[n-1];
        char ft=temp[0];
        char lt=temp[n-1];

        if(fs==ft || ls==lt ) return 1;
        if(fs==lt && ls==ft && freq[ft-'a']==1 && freq[lt-'a']==1) return 3;
        else return 2;
        return -1;
        
    }
};