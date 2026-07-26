class Solution {
public:
    int getdigit(int n) {
        int ret=0;
        while (n>0){
            ret+=(n%10)*(n%10);
            n/=10;
        }
        return ret;
    }

    bool isHappy(int n) {
        if(n==1 || n==7) return true;
        if(n<10) return false;
        unordered_set<int> s;
        while (n != 1 && s.find(n) == s.end()) {
            s.insert(n);
           n = getdigit(n); 
        }
        return n == 1;
    }
};