class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        backtrack(ret, phone, digits, 0, "");
        return ret;
    }

    void backtrack(vector<string>& ret, vector<string>& phone, string& digits, int i, string cur) {
        if (i == digits.length()) {
            ret.push_back(cur);
            return;
        }
        for (char c : phone[digits[i] - '0']) {
            backtrack(ret, phone, digits, i + 1, cur + c);
        }
    }
};