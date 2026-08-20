class Solution {
public:
    bool checkInclusion(string p, string s) {
       int p_size=p.size();
        int n_size=s.size();
        int n=n_size-p_size+1;
        if(p_size>n_size){
            return false;
        }



        unordered_map<char,int>mp1;
        for(int i=0;i<p_size;i++){
            mp1[p[i]]++;
        }


        unordered_map<char,int>mp2;


        for(int i=0;i<p_size;i++){
             mp2[s[i]]++;
        }
        if(mp1==mp2){
            return true;
        }


        for(int i=p_size;i<n_size;i++){
            mp2[s[i]]++;

            mp2[s[i-p_size]]--;
            if (mp2[s[i-p_size]]==0){
                mp2.erase(s[i-p_size]);
            }
            
            if (mp1==mp2) {
                return true;
            }

        }

            
        return false; 
    }
};

