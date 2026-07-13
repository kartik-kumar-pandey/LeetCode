class Solution {
    int st, en;
    vector<int> ans;

    int getNum(vector<int>& nums, int pos) {
        int x = 0;
        for (int i = 0; i < pos; i++) {
            x = x * 10 + nums[i];
        }
        return x;
    }

    void generate(vector<int>& nums, int pos) {
        if (pos > 9) return;
        int curNum = getNum(nums, pos);
        if (curNum > en) return;

        if (curNum >= st && curNum <= en) ans.push_back(curNum);

        if (nums[pos - 1] < 9) {
            nums[pos] = nums[pos - 1] + 1;
            generate(nums, pos + 1);
        }
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        st = low;
        en = high;
        ans.clear();
        vector<int> nums(9);

        for (int i = 1; i <= 9; i++) {
            nums[0] = i;
            generate(nums, 1);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
