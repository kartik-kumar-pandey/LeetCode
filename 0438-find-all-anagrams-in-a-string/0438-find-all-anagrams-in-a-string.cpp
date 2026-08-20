class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int p_size=p.size();
        int n_size=s.size();
        int n=n_size-p_size+1;
        unordered_map<char,int>mp1;
        for(int i=0;i<p_size;i++){
            mp1[p[i]]++;
        }
        vector<int>ret;
         unordered_map<char,int>mp2;
        for(int i=0;i<p_size;i++){
             mp2[s[i]]++;
        }
        if(mp1==mp2){
            ret.push_back(0);
        }
        for(int i=p_size;i<n_size;i++){
            mp2[s[i]]++;

            mp2[s[i-p_size]]--;
            if (mp2[s[i-p_size]]==0){
                mp2.erase(s[i-p_size]);
            }
            
            if (mp1==mp2) {
                ret.push_back(i-p_size+1);
            }

        }

            
        return ret;
    }
};