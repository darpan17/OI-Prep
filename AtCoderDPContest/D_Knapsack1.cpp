#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)
#define ll long long

using namespace std;

ll dp[105][100005];

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,w; cin >> n >> w;
	int wt[n+5]; ll val[n+5]; FORE(i,1,n) cin >> wt[i] >> val[i];
	FORE(i,1,n){
		FORE(j,1,w){
			if(wt[i] > w || j < wt[i]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i]]+val[i]);
			}
		}
	}
	cout << dp[n][w];
	return 0;
}
