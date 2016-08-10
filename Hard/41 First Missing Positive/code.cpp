// At first, the condition that the function return is left_missing == right_missing.
// BUT this is a wrong algorithm!
// [2,1,1,0,3,0,4,3,2]
// Though AC, I think it's not a O(n) solution.

// Yes, the trivial O(n^2) solution has the same runtime!
// It's a bad algorithm!

// LeetCode do not check time complexity.

// It's even worse than first sorting!

/*
#include <algorithm>

class Solution {
public:
    int left(vector<int>& nums, int missing){
        for(int i=0;i<nums.size();i++)
            if(nums[i] == missing)
                missing++;
        return missing;
    }
    
    int right(vector<int>& nums, int missing){
         for(int i=nums.size()-1;i>=0;i--)
            if(nums[i] == missing)
                missing++;
        return missing;
    }

    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        int pre_left = 1;
        int pre_right = 1;
        int pre = 1;
        while(1){
            int left_missing = left(nums, pre);
            int right_missing = right(nums, pre);
            if(left_missing == pre_left && right_missing == pre_right)
                return left_missing;
            pre = max(left_missing, right_missing);
            pre_left = left_missing;
            pre_right = right_missing;
        }
    }
};

*/

/*
class Solution {
public:
    bool isMissing(vector<int>& nums, int missing){
        for(int i=0;i<nums.size();i++)
            if(nums[i] == missing)
                return false;
        return true;
    }

    int firstMissingPositive(vector<int>& nums) {
        for(int i=1;;i++){
            if(isMissing(nums, i))
                return i;
        }
    }
};
*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 1 || nums[i] > nums.size())
                nums[i] = nums.size()+1;
        }
        for(int i=0;i<nums.size();i++){
            int x = nums[i] > 0 ? nums[i]:-nums[i];
            if(x == nums.size()+1)
                continue;
            if(nums[x-1] > 0)
                nums[x-1] = -nums[x-1];
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i] > 0)
                return i+1;
        return nums.size()+1;
    }
};