#include <cmath>

class Solution {
public:

    bool check(int n){
        int sq = (int)(sqrt(n) + 1e-10);
        if(sq * sq == n)
            return true;
        return false;
    }

    bool check2(int n){
        for(int i=(int)sqrt(n);i>0;i--){
            if(2 * i * i < n)
                return false;
            if(check(n - i*i))
                return true;
        }
        return false;
    }
    
    bool check3(int n){
        while(n % 4 == 0)
            n /= 4;
        if(n % 8 == 7)
            return false;
        return true;
    }

    int numSquares(int n) {
        if(check(n))
            return 1;
        if(check2(n))
            return 2;
        if(check3(n))
            return 3;
        return 4;
    }
};