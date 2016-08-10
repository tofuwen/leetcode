#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib> // atoi
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
	// int change(string s){
	// 	return atoi(s.c_str());
	// }

	// string change(int a){
	// 	stringstream ss;
	// 	ss >> a;
	// 	string ans;
	// 	ss << ans;
	// 	return ans;
	// }

	// vector<string> everything(string num){
	// 	vector<string> ans;
	// 	if(num.length() == 0){
	// 		ans.push_back("");
	// 		return ans;
	// 	}
	// 	for(int i=1;i<=num.length();i++){
 //        	string cur = num.substr(0,i);
 //        	string other = num.substr(i);
 //        	cur += '+';
 //        	vector<string> hold = everything(other);
 //        	for(int j=0;j<hold.size();j++)
 //        		ans.push_back(cur + hold[j]);
 //        	cur[cur.length()-1] = '-';
 //        	hold = everything(other);
 //        	for(int j=0;j<hold.size();j++)
 //        		ans.push_back(cur + hold[j]);
 //        	cur[cur.length()-1] = '*';
 //        	hold = everything(other);
 //        	for(int j=0;j<hold.size();j++)
 //        		ans.push_back(cur + hold[j]);
 //        }
 //        return ans;
	// }

 //    vector<string> addOperators1(string num, int target) {
 //        vector<string> ans;
 //        if(num.length() == 0){
 //        	if(target == 0)
 //        		ans.push_back("");
 //        	return ans;
 //        }
 //        for(int i=1;i<=num.length();i++){
 //        	string cur = num.substr(0,i);
 //        	int now = change(cur);
 //        	string other = num.substr(i);
 //        	cur += '+';
 //        	vector<string> hold = addOperators1(other, target - now);
 //        	for(int j=0;j<hold.size();j++)
 //        		ans.push_back(cur + hold[j]);
 //        	cur[cur.length()-1] = '-';
 //        	hold = addOperators1(other, now - target);
 //        	for(int j=0;j<hold.size();j++)
 //        		ans.push_back(cur + hold[j]);
 //        	cur[cur.length()-1] = '*';
 //        	if(now != 0){
 //        		if(target % now == 0)
 //        			hold = addOperators1(other, target / now);
 //        		else
 //        			hold.clear();
 //        	}
 //        	else{
 //        		if(target == 0)
 //        			hold = everything(other);
 //        		else
 //        			hold.clear();
 //        	}
 //        	for(int j=0;j<hold.size();j++)
 //        		ans.push_back(cur + hold[j]);
 //        }
 //        return ans;
 //    }

 //    bool ok(string s){
 //    	for(int i=0;i<s.length();i++)
 //    		if(!(s[i]>='0' && s[i]<='9'))
 //    			s[i] = ' ';
 //    	stringstream ss(s);
 //    	string now;
 //    	while(ss >> now){
 //    		if(now.length() >= 2 && now[0] == '0')
 //    			return false;
 //    	}
 //    	return true;
 //    }

 //    vector<string> addOperators(string num, int target) {
 //    	vector<string> ans = addOperators1(num, target);
 //    	for(int i=0;i<ans.size();i++){
 //        	int length = ans[i].length() - 1;
 //        	ans[i] = ans[i].substr(0, length);
 //        }
 //        sort(ans.begin(), ans.end());
	// 	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	// 	vector<string> trueAns;
	// 	for(int i=0;i<ans.size();i++){
	// 		if(ok(ans[i]))
	// 			trueAns.push_back(ans[i]);
	// 	}
	// 	return trueAns;
 //    }
    
    void solve(vector<string> & ans, long long pv, char po, string cur, const int target, long long now, int pos, const string & num){
        if(pos >= num.length()){
            if(now == target)
                ans.push_back(cur);
            return;
        }
        for(int i=pos+1;i<=num.length();i++){
            string thiscur = num.substr(pos, i-pos);
            if(thiscur[0] == '0' && thiscur.length() > 1) // don't allow 01 == 1
                break;
            long long thisnow = stoll(thiscur);
            solve(ans, thisnow, '+', cur+'+'+thiscur, target,thisnow+now, i, num);
            solve(ans, thisnow, '-', cur+'-'+thiscur, target,now-thisnow, i, num);
            solve(ans, thisnow*pv, po, cur+'*'+thiscur, target,(po=='-')?now+pv-pv*thisnow:now-pv+pv*thisnow, i, num);
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.length() == 0)
            return ans;
        for(int i=1;i<=num.length();i++){
            string cur = num.substr(0,i);
            if(cur[0] == '0' && cur.length() > 1) // don't allow 01 == 1
                break;
            long long now = stoll(cur);
            solve(ans, now, '#', cur, target, now, i, num);
        }
    }
};



int main()
{
	Solution mySolution;
	vector<string> ans = mySolution.addOperators("105", 5);
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << endl;
	return 0;
}

