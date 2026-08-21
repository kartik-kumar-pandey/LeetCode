class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n=words.size();
        string curr="";
        for(int i=0;i<n;i++){
            curr+=words[i];
            if(curr==s){
                return true;
            }
        }
        return false;
    }
};