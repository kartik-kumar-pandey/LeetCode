class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ret = 0;
        unordered_set<int> s;
        unordered_set<int> d;
        for (int i : nums) {
            if (d.count(i))
                continue;
            if (s.count(i)) {
                ret -= i;
                d.insert(i);
            } else {
                s.insert(i);
                ret += i;
            }
        }
        return ret;
    }
};