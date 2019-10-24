#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

const ll MOD = 1000000007;
const ll LINF = ~1ULL<<50;
string grid[1005];
ll dp[1005][1005];

int main(){
	int n,m; cin >> n >> m;
	FOR(i,n) cin >> grid[i];
	FOR(i,n){
		if(grid[i][0] == '#'){
			while(i++ != n){
				dp[i][0] = LINF;
			}
		}else{
			dp[i][0] = 1;
		}
	}
	FOR(i,m){
		if(grid[0][i] == '#'){
			while(i++ != m){
				dp[0][i] = LINF;
			}
		}else{
			dp[0][i] = 1;
		}
	}
	FORE(i,1,n-1){
		FORE(j,1,m-1){
			if(grid[i][j] == '#'){
				dp[i][j] = LINF;
			}else{
				if(dp[i-1][j] > 0 && dp[i][j-1] > 0){
					dp[i][j] = ((dp[i-1][j]%MOD)+(dp[i][j-1]%MOD))%MOD;
				}else{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
	}
	cout << max(dp[n-1][m-1],0LL);
	return 0;
}
