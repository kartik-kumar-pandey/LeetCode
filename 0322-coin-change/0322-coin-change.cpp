class Solution {
public:
    int coinChangeRec(vector<int>& coins, int amount, vector<int>& memo) {
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;

    if (memo[amount] != -1) return memo[amount];

    int res = INT_MAX;
    for (int c : coins) {
        int sub = coinChangeRec(coins, amount - c, memo);
        if (sub != INT_MAX) {
            res = min(res, sub + 1);
        }
    }

    memo[amount] = res; 
    return res;
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> memo(amount + 1, -1);
    int ans = coinChangeRec(coins, amount, memo);
    return ans == INT_MAX ? -1 : ans;
}


};