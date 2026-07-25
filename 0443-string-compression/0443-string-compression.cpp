class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int i=0;

        while(i<chars.size()){
            char ch=chars[i];
            int cnt=0;

            while(i<chars.size()&&chars[i]==ch){
                cnt++;
                i++;
            }

            s+=ch;
            if(cnt==1){
                continue;
            }
            s+=to_string(cnt);
        }

        for(int i=0;i<s.size();i++){
            chars[i]=s[i];
        }

        return s.size();
    }
};