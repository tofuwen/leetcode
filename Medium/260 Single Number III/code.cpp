class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor0 = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
            xor0 ^= nums[i];
        int p; 
        for(p=0;;p++)
            if((1<<p) & xor0)
                break;
        int xor1 = 0;
        int xor2 = 0;
        for(int i=0;i<n;i++){
            if((1<<p) & nums[i])
                xor1 ^= nums[i];
            else
                xor2 ^= nums[i];
        }
        vector<int> ans;
        ans.push_back(xor1);
        ans.push_back(xor2);
        return ans;
    }
};