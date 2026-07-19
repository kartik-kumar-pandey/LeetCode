class Solution {
public:
    string smallestSubsequence(string s) {
       stack<char>st;
        set<char>se;
        unordered_map<char,int>mp;
        string res = "";
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]] = i;
        }
        for(int i=0;i<n;i++)
        {
            if(se.find(s[i])!=se.end())
            {
                continue;
            }
            while(st.empty()!=true && st.top()>=s[i] && mp[st.top()]>i)
            {
                int val = st.top();
                st.pop();
                se.erase(val);
            }
            st.push(s[i]);
            se.insert(s[i]);
        }
        while(st.empty()!=true)
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res; 
    }
};