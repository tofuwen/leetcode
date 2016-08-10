#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {

public:
    bool isMatch(string s, string p) {
        int sSize = s.size(), pSize = p.size(), i, j;
        bool checked[sSize+1][pSize+1];
//        fill_n(&matched[0][0], (sSize+1)*(pSize+1), false);

        for(j=2, checked[0][0]=true, checked[0][1]= false; j<=pSize; ++j) // match s[0..0]
            checked[0][j] = p[j-1] == '*'? checked[0][j-2]  : false;
        for(i=1; i<=sSize; ++i)
        for(j=1, checked[i][0]=false; j<=pSize; ++j)
        {
            if(p[j-1]=='*') // case (1)
                checked[i][j] = (j>1) && ( checked[i][j-2]  || ( ( checked[i-1][j]) && (s[i-1]== p[j-2] || p[j-2] == '.')) );
            else // case (2)
                checked[i][j] = checked[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');        
        }
        return checked[sSize][pSize];
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