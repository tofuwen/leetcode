#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isStar(const string & s){
		//cout << s << endl;
		return s[s.length() - 1] == '*';
	}


	bool isMatch(vector<string> & regex, string s){
		// for(int i=0;i<regex.size();i++)
		// 	cout << regex[i] << endl;
		// cout << endl;
		if(s.length() == 0 && regex.size() == 0)
			return true;
		if(regex.size() == 0)
			return false;
		int n = regex.size();
		const string cur = regex[n-1];
		//cout << cur << endl;
		regex.pop_back();
		//cout << cur << endl;
		if(!isStar(cur)){
			int l = cur.length();
			if(s.length() < l){
				regex.push_back(cur);
				return false;
			}
			for(int i=0;i<l;i++)
				if(s[i] != cur[i] && cur[i] != '.'){
					regex.push_back(cur);
					return false;
				}
			bool ok = isMatch(regex, s.substr(l));
			regex.push_back(cur);
			return ok;
		}
		//cout << "kao" << endl;
		if(cur[0] == '.'){
			bool ok = false;
			for(int i=0;i<=s.length();i++)
				ok = ok || isMatch(regex, s.substr(i));
			regex.push_back(cur);
			return ok;
		}
		else{
			bool ok = false;
			for(int i=0;i<=s.length();i++){
				if(i != 0 && s[i-1] == cur[0])
					ok = ok || isMatch(regex, s.substr(i));
				else
					if(i == 0)
						ok = ok || isMatch(regex, s.substr(i));
					else
						break;
			}
			regex.push_back(cur);
			return ok;
		}
	}

    bool isMatch(string s, string p) {
    	vector<int> v;
    	int l = p.length();
    	for(int i=0;i<l;i++)
    		if(p[i] == '*')
    			v.push_back(i);
    	//cout << "v" << v.size() << endl;
        vector<string> ans;
        int pre = 0;
        for(int i=0;i<v.size();i++){
        	int now = v[i];
        	if(now - 1 - pre > 0)
        		ans.push_back(p.substr(pre, now-1-pre));
        	ans.push_back(p.substr(now-1, 2));
        	pre = now + 1;
        }
        if(pre != l)
        	ans.push_back(p.substr(pre));
        // for(int i=0;i<ans.size();i++)
        // 	cout << ans[i] << endl;
        reverse(ans.begin(), ans.end());
        return isMatch(ans, s);
    }
};

int main()
{
	freopen("input.txt", "r", stdin);
	string test, regex;
	Solution mySolution; 
	while(cin >> test >> regex){
		cout << mySolution.isMatch(test, regex) << endl;
	}
	return 0;
}