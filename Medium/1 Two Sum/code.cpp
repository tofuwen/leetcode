#include <algorithm>

struct num{
    int val;
    int p;
    num(int val, int p):val(val),p(p){}
    friend bool operator < (const num& a, const num& b){
        return a.val < b.val;
    }
};

bool out(int index, int size){
    return index >= size || index < 0;
}

int find(vector<num> &v, int begin, int end, int want, int thisindex){
    if(end <= begin)
        return 0;
    int mid = (begin+end)/2;
    if(v[mid].val == want){
        if(v[mid].p != thisindex)
            return v[mid].p;
        if(!out(mid-1, v.size()))
            if(v[mid-1].val == want)
                return v[mid-1].p;
        return v[mid+1].p;
    }
    if(v[mid].val > want)
        return find(v, begin, mid, want, thisindex);
    return find(v, mid+1, end, want, thisindex);
}

int find(vector<num> &v, int want, int thisindex){
    return find(v, 0, v.size(), want, thisindex);
}

bool check(int index, int & x, vector<num> & v, int target, int thisindex){
    x = find(v, target - v[index].val, thisindex);
    if(x)
        return true;
    return false;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<num> hold;
        vector<int> ans;
        int size = nums.size();
        for(int i=0;i<size;i++)
            hold.push_back(num(nums[i], i+1));
        sort(hold.begin(), hold.end());
        for(int i=0;i<size;i++){
            int x;
            if(check(i,x,hold, target, hold[i].p)){
                ans.push_back(hold[i].p);
                ans.push_back(x);
                sort(ans.begin(), ans.end());
                return ans;
            }
        }
    }
};