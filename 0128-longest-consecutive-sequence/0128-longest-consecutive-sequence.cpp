class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
         return 0;
        
        sort(nums.begin(), nums.end());
        int l = 1;
        int current = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    current++;
                } else {
                    l = max(l, current);
                    current = 1;
                }
            }
        }
        
        return max(l, current);
    }
};