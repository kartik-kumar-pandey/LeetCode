class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        int n1=s.size();
        int n2=t.size();
    
        while(i<n1&&j<n2){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }
    
        return n2-j;
    }
};