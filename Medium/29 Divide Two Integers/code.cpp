class Solution {
public:
    // directly "minus the divisor" will result into TLE!
    // int divide(int dividend, int divisor) {
    //     if(dividend == 0)
    //         return 0;
    //     int ans = 0;
    //     int flag = 1;
    //     if(dividend < 0){
    //         flag = 0;
    //         dividend = -dividend;
    //     }
    //     while(dividend > 0 && dividend >= divisor){
    //         ans++;
    //         dividend -= divisor;
    //     }
    //     if(flag)
    //         return ans;
    //     return -ans;
    // }
    int divide(int dividend, int divisor) {
        if(divisor == -2147483648){
            if(dividend == divisor)
                return 1;
            return 0;
        }
        if(dividend == -2147483648){
            if(divisor == 1)
                return dividend;
            if(divisor == -1)
                return 2147483647;
            if(divisor == 2)
                return -(1<<30);
            if(divisor == -2)
                return 1<<30;
            dividend++;
        }
        if(divisor == 1)
            return dividend;
        if(dividend == 0)
            return 0;
        if(divisor == 0)
            return 1<<30;
        int flag = 0;
        if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            flag = 1;
        if(dividend < 0)
            dividend = -dividend;
        if(divisor < 0)
            divisor = -divisor;
        if(dividend < divisor)
            return 0;
        int i, j;
        for(i=30;i>=0;i--)
            if(dividend & (1 << i))
                break;
        for(j=30;j>=0;j--)
            if(divisor & (1 << j))
                break;
        int h = 1 << (i-j);
        int k = dividend - (divisor << (i-j));
        while(k < 0){
            k += divisor;
            h--;
        }
        h += divide(k, divisor);
        //int ans = 1 << (i-j) + divide(dividend - (divisor << (i-j)), divisor);
        if(flag)
            return h; 
        return -h;
    }
};


int main()
{
    freopen("data.txt", "r", stdin);
    int dividend, divisor;
    Solution mySolution;
    while(scanf("%d%d", &dividend, &divisor)){
        printf("%d\n", mySolution.divide(dividend, divisor));
    }
    return 0;
}