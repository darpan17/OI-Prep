#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

const int MOD = 15746;
int dp[1000006];

int DP(int n){
	if(n <= 1) return dp[n] = 1;
	if(dp[n] > 0) return dp[n];
	return dp[n] = ((DP(n-2)%MOD)+(DP(n-1)%MOD))%MOD;
}

int main(){
	int n; cin >> n;
	cout << DP(n);
	return 0;
}
