#include <sstream>

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<int> v[30];
        for(int i=0;i<pattern.length();i++)
            v[pattern[i] - 'a'].push_back(i);
        stringstream ss(str);
        vector<string> match;
        string s;
        while(ss >> s){
            match.push_back(s);
        }
        if(match.size() != pattern.length())
            return false;
        set<string> matched;
        set<string>::iterator iter;
        for(int i=0;i<30;i++){
            for(int j=0;j<v[i].size();j++){
                if(j == 0){
                    iter = matched.find(match[v[i][j]]);
                    if(iter != matched.end())
                        return false;
                    matched.insert(match[v[i][j]]);
                }
                else{
                    if(v[i].size() == 1)
                        break;
                    if(match[v[i][j-1]] != match[v[i][j]])
                        return false;
                }
            }
        }
        return true;
    }
};