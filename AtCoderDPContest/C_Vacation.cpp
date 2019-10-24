#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

int main(){
	int n; cin >> n;
	int a[n],b[n],c[n]; FOR(i,n) cin >> a[i] >> b[i] >> c[i];
	int dp[n][3]; FOR(i,n) dp[i][0] = dp[i][1] = dp[i][2] = 0;
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];
	FORE(i,1,n-1){
		dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a[i];
		dp[i][1] = max(dp[i-1][0],dp[i-1][2])+b[i];
		dp[i][2] = max(dp[i-1][0],dp[i-1][1])+c[i];
	}
	cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	return 0;
}
