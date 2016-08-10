class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int can1 = -1, can2 = -1, n1 = 0, n2 = 0;
        for(int i=0;i<nums.size();i++){
            if(n1 == 0 && nums[i] != can2){
                can1 = nums[i];
                n1 = 1;
                continue;
            }
            if(can1 == nums[i]){
                n1++;
                continue;
            }
            if(n2 == 0){
                can2 = nums[i];
                n2++;
                continue;
            }
            if(can2 == nums[i]){
                n2++;
                continue;
            }
            n1--;
            n2--;
        }
        int num1 = 0, num2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == can1)
                num1++;
            if(nums[i] == can2)
                num2++;
        }
        if(num1 > n / 3)
            ans.push_back(can1);
        if(can1 != can2 && num2 > n / 3)
            ans.push_back(can2);
        return ans;
    }
};