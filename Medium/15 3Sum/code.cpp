#include <algorithm>

class Solution {
public:
    bool ok(int want, int low, int high, vector<int>& nums){
        if(low >= high)
            return false;
        int mid = (low + high) / 2;
        if(nums[mid] ==  want)
            return true;
        if(nums[mid] > want)
            return ok(want, low, mid, nums);
        return ok(want, mid+1, high, nums);
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0)
                return ans;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                int want = -nums[i]-nums[j];
                if(want < nums[j])
                    break;
                if(ok(want, j+1, nums.size(), nums)){
                    vector<int> h;
                    h.push_back(nums[i]);
                    h.push_back(nums[j]);
                    h.push_back(want);
                    ans.push_back(h);
                }
            }
        }
        return ans;
    }
};