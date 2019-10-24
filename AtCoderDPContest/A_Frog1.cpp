#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)

typedef long long ll;

using namespace std;

ll dp[100005];

int main(){
	int n; cin >> n;
	int h[n]; FOR(i,n) cin >> h[i];
	dp[0] = 0; dp[1] = abs(h[1]-h[0]);
	FORE(i,2,n-1) dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
	cout << dp[n-1];
	return 0;
}
