class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ret = 0;
        while (1)
            if (nums.size() > 1) {
                string curr = "";
                int f = nums[0];
                int e = nums.back();

                nums.erase(nums.begin());
                nums.pop_back();
                curr += to_string(f);

                curr += to_string(e);

                ret += stoll(curr);
                cout << stoll(curr) << endl;
            } else {
                if (!nums.empty())
                    ret += nums[0];
                break;
            }

        return ret;
    }
};