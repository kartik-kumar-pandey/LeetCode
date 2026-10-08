class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string res = "";

        for(char c : s){
            if(st.empty()){
                st.push(c);
            }
            else if(c == '('){
                st.push(c);
                res += c;
            }
            else if(c == ')'){
                st.pop();
                if(!st.empty()){
                    res += c;
                }
            }
        }
        return res;
    }
};