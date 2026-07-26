class Solution {
public:
    void back(string s,int open_c,int close_c,vector<string>& ret,int n){
        if(s.size()==2*n){
            ret.push_back(s);
        }
        if(open_c<n)
        back(s+'(',open_c+1,close_c,ret,n);

        if(close_c<open_c)
        back(s+')',open_c,close_c+1,ret,n);

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ret;
        back("",0,0,ret,n);
        return ret;

    }
};