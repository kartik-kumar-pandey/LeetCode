class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ret;
        stack<long long> st;

        for(int x : nums) {
            long long val = x;

            while(!st.empty() && st.top() == val) {
                st.pop();
                val *= 2;
            }

            st.push(val);
        }

        while(!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
