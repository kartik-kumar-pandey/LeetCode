class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int den = 1;
        
        stringstream ss(expression);
        int nextNum, nextDen;
        char slash; 
        
        while (ss >> nextNum >> slash >> nextDen) {
            num = num * nextDen + den * nextNum;
            den = den * nextDen;
            
            int commonDivisor = abs(gcd(num, den));
            num /= commonDivisor;
            den /= commonDivisor;
        }
        
        return to_string(num) + "/" + to_string(den);
    }
};