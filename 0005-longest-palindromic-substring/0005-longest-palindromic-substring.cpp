class Solution {
private:
    int expandFromCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--; 
            right++; 
        }
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;     
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            
            int len1 = expandFromCenter(s, i, i);
            
            int len2 = expandFromCenter(s, i, i + 1);
            
            int currentMax = max(len1, len2);
            
            if (currentMax > maxLength) {
                maxLength = currentMax;
                start = i - (currentMax - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};