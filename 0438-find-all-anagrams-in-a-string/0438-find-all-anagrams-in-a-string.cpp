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

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp2;
            for(int j=i;j<i+p_size;j++){
                mp2[s[j]]++;
            }
            if(mp1==mp2){
                ret.push_back(i);
            }
        }
        return ret;
    }
};