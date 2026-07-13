class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>s1;
        int left=0;
        int ret=0;

        for(int right=0;right<s.size();right++){
            while(s1.count(s[right])){
                s1.erase(s[left]);
                left++;
            }

            s1.insert(s[right]);

            ret=max(ret,right-left+1);

        }
        return ret;
        
    }
};