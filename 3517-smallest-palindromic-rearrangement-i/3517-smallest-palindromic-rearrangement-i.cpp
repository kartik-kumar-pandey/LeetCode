class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        string ret="";
        int n=s.size();
        for(auto it=mp.begin();it!=mp.end();it++){
            int val=it->second;
            
            val=val/2;
            ret.append(val,it->first);
            it->second-=(val * 2);
            
        }
        sort(ret.begin(),ret.end());
        string ret2=ret;
        
        reverse(ret2.begin(),ret2.end());

        char center = '\0';
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second){
                if(center == '\0' || it->first < center) {
                    center = it->first;
                }
            }
        }

        if(center != '\0') {
            ret += center;
        }

        return ret+ret2;
    }
};
