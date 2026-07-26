class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string p = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                p += s[i];
            }
            if (s[i] == ' ') {
                if (!p.empty()) { // only add to vector if p is not empty
                    v.push_back(p);
                }
                p = "";
            }
        }
        if (!p.empty()) {
            v.push_back(p);
        }
        reverse(v.begin(), v.end());
        string result = "";
        for (int i = 0; i < v.size(); i++) {
            result += v[i];
            if (i < v.size() - 1) { 
                result += " ";
            }
        }
        return result;
    }
};