class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = nums[0];
        int fast = nums[low];
        while(fast != low){
            low = nums[low];
            fast = nums[nums[fast]];
        }
        low = 0;
        while(low != fast){
            fast = nums[fast];
            low = nums[low];
        }
        return low;
    }
};