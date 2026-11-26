class Solution {
public:
    bool canAliceWin(int n) {
        int count = 0;      
        int s_remove = 10;
        while (n >= s_remove) {
            n -= s_remove;
            s_remove--;  
            count++;      
        }
        return count%2!=0;
    }
};