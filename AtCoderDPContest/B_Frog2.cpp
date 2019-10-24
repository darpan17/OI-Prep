#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

ll dp[100005],h[100005];

int main(){
	int n,k; cin >> n >> k;
	FOR(i,n) cin >> h[i];
	FOR(i,100005) dp[i] = LLONG_MAX;
	dp[0] = 0; 
	FORE(i,1,k-1){
		FOR(j,i){
			dp[i] = min(dp[i],abs(h[i]-h[j])+dp[j]);
		}
	}
	FORE(i,k,n-1){
		FORE(j,i-k,i-1){
			dp[i] = min(dp[i],abs(h[j]-h[i])+dp[j]);
		}
	}
	cout << dp[n-1];
	return 0;
}
