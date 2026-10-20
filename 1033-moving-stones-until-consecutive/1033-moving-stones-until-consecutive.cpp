class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> p(3,0);

        p[0] = a;
        p[1] = b;
        p[2] = c;

        sort(p.begin(), p.end());

        vector<int> v(2,0);

        int left = p[1] - p[0];
        int right = p[2] - p[1];

        // already consecutive
        if(left == 1 && right == 1) {
            return v;
        }

        // minimum moves
        if(left <= 2 || right <= 2) {
            v[0] = 1;
        } else {
            v[0] = 2;
        }

        // maximum moves
        v[1] = left + right - 2;

        return v;
    }
};