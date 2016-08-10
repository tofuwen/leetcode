class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        long long hold = n;
        while(hold>0)
        {
            if(hold%2)
                num++;
            hold /= 2;
        }
        return num;
    }
};