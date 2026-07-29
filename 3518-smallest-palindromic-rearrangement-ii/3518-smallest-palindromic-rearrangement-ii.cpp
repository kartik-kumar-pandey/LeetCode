class Solution {
public:
    using ll = long long;
    const ll LIM = 1000000LL + 5;

   ll nCr(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        ll ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > LIM) return LIM;
        }
        return ans;
    }

    ll countWays(map<char,int> &mp) {
        int total = 0;
        for (auto &x : mp)
            total += x.second;

        ll ways = 1;
        int rem = total;

        for (auto &x : mp) {
            if (x.second == 0) continue;
            ways *= nCr(rem, x.second);
            if (ways > LIM) ways = LIM;
            rem -= x.second;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {

        int n = s.size();

        map<char,int> mp;
        for (int i = 0; i < n / 2; i++)
            mp[s[i]]++;

        if (countWays(mp) < k)
            return "";

        string first = "";

        while ((int)first.size() < n / 2) {

            for (char c = 'a'; c <= 'z'; c++) {

                if (mp[c] == 0) continue;

                mp[c]--;

                ll ways = countWays(mp);

                if (ways >= k) {
                    first += c;
                    break;
                }

                k -= ways;
                mp[c]++;
            }
        }

        string ans = first;

        if (n % 2)
            ans += s[n / 2];

        reverse(first.begin(), first.end());
        ans += first;

        return ans;
    }
};