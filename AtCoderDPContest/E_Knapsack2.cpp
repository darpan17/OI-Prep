#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)
#define ll long long

using namespace std;

ll dp[105][100005],wt[105];
int val[105];

int main(){
	int n; ll w; cin >> n >> w;
	FORE(i,1,n) cin >> wt[i] >> val[i];
	FORE(i,1,100005) dp[0][i] = 123456789123456789;
	FORE(i,1,n+1){
		FOR(j,100005){
			if(val[i] > j){
				dp[i][j] = dp[i-1][j];	
			}else{
				dp[i][j] = min(dp[i-1][j],dp[i-1][j-val[i]]+wt[i]);
			}
		}
	}
	int ans = 0;
	for(int i = 100004; i > 0; i--){
		if(dp[n][i] <= w){
			ans = i;
			break;
		}
	}
	cout << ans;
	return 0;
}
