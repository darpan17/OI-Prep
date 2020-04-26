#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x,a) memset(x,a,sizeof(x))
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

ld dp[3005][3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	ld a[n+5]; FOR(i,1,n) cin >> a[i];
	// dp[i][j] = probability to have j heads in first i tosses 
	dp[0][0] = 1.0;
	FOR(i,1,n) {
		FOR(j,0,n) {
			if(j > 0) dp[i][j] = dp[i-1][j-1]*a[i];
			dp[i][j] += dp[i-1][j]*(1-a[i]);
		}
	}	
	ld ans = 0;
	FOR(i,n/2+1,n) ans += dp[n][i];
	cout << fixed << setprecision(10) << ans;
}	
 
