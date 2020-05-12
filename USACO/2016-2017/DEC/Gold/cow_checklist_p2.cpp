/*
SOLUTION: Standard 2D DP.
dp[i][j][0/1] = min cost for visiting first i Holsteins and j Gurenseys
0 if the current cow visited was a Holstein else 1 if Guernsey
*/
#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x,a) memset((x),(a),sizeof(x)) 
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

const int MX = 2005;
ll dp[MX][MX][2];
pii h[MX],g[MX];

inline ll dist(pii& a,pii& b) {
	ll dx = a.F-b.F;
	ll dy = a.S-b.S;
	return dx*dx+dy*dy;
}

int main() {
	ifstream fin("checklist.in"); 
	ofstream fout("checklist.out");
	#define cin fin
	#define cout fout
	int n,m; cin >> n >> m;
	FOR(i,1,n)cin >> h[i].F >> h[i].S;
	FOR(i,1,m)cin >> g[i].F >> g[i].S;
	F0R(i,n+5)F0R(j,m+5)dp[i][j][0] = dp[i][j][1] = 1e18;
	dp[1][0][0] = 0;
	h[0] = g[0] = {-1e9,-1e9};
	FOR(i,1,n) {
		F0R(j,m+1) {
			dp[i][j][0] = min(dp[i][j][0],min(dp[i-1][j][0] + dist(h[i],h[i-1]),dp[i-1][j][1] + dist(h[i],g[j])));
			dp[i][j][1] = min(dp[i][j][1],min(dp[i][j-1][0] + dist(g[j],h[i]),dp[i][j-1][1] + dist(g[j],g[j-1])));
		}
	}
	cout << dp[n][m][0];
}	 
