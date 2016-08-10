#include <algorithm>
#include <vector>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        if(x == 0)
            return 0;
        bool flag = true;
        if(x < 0){
            x = -x;
            flag = false;
        }
        vector<int> v;
        while(x > 0){
            v.push_back(x % 10);
            x /= 10;
        }
        long long ans = 0;
        for(int i=0;i<v.size();i++){
            ans *= 10;
            ans += v[i];
        }
        if(ans > INT_MAX)
            return 0;
        if(flag)
            return ans;
        return -ans;
    }
};