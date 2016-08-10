class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can, n = 0;
        for(int i=0;i<nums.size();i++){
            if(!n){
                n = 1;
                can = nums[i];
            }
            else{
                if(nums[i] == can)
                    n++;
                else
                    n--;
            }
        }
        return can;
    }
};