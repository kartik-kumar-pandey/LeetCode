class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxLength = 1;
        int currentLength = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currentLength++;
            } else {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = max(maxLength, currentLength);

        currentLength = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                currentLength++;
            } else {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = max(maxLength, currentLength);

        return maxLength;
    }
};