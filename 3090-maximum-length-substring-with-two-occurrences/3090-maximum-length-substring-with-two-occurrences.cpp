class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int ret = 0;
        int left = 0;

        unordered_map<char, int> mp;

        for (int right = 0; right < n; right++) {
            mp[s[right]]++;

            while (mp[s[right]] > 2) {
                mp[s[left]]--;
                left++;
            }

            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};