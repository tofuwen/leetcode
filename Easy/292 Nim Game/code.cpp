#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	/*
	// runtime error! n can be large
	int canWin[100000];

	int dp(int n){
		if(canWin[n] != -1)
			return canWin[n];
		int ok = 0;
		for(int i=1;i<=3;i++){
			if(n-i>=0 && !dp(n-i))
				ok = 1;
		}
		return canWin[n] = ok;
	}

    int canWinNim(int n) {
        memset(canWin, -1, sizeof(canWin));
        canWin[0] = 0;
        return dp(n);
    }
    */
   	bool canWinNim(int n) {
       	return n % 4 != 0;
    }
};

int main()
{
	freopen("data.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n;
	while(cin >> n){
		Solution mySolution;
		cout << mySolution.canWinNim(n) << endl;
	}
	return 0;
}