#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int exists[1000];
        memset(exists, -1, sizeof(exists));
        int ans = 0;
        int first = 0, second = 0;
        int l = s.length();
        while(second < l){
            int c = s[second];
            if(exists[c] == -1){
                exists[c] = second;
            }
            else{
                first = max(first, exists[c] + 1);
                exists[c] = second;
            }
            int cur = second - first + 1;
            //cout << first << " " << second << endl;
            ans = max(ans, cur);
            second++;
        }
        return ans;
    }
};

int main()
{
    freopen("data.txt", "r", stdin);
    string s;
    while(cin >> s){
        Solution my;
        cout << my.lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}