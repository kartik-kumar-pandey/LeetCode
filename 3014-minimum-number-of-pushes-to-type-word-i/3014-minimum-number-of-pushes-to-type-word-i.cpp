class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ret = 0;

        for(int i = 0; i < n; i++){
            ret += i / 8 + 1;
        }

        return ret;
    }
};