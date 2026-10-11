class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0) {
                int x = nums[i];
                ret += (x * x);
            }
        }
        return ret;
    }
};