/*
SOLUTION: Observe that you can create an edge b/w nodes u and v without 
intersecting with any other edge iff abs(a[u]-b[v]) <= 4 and 
u is not connected to any other previous edge and so is v.
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

const int MX = 1005;
int dp[MX][MX];

int main() {
	ifstream fin("nocross.in");
	ofstream fout("nocross.out");
	#define cin fin
	#define cout fout
	int n; cin >> n;
	int a[n+5]; FOR(i,1,n) cin >> a[i];
	int b[n+5]; FOR(i,1,n) cin >> b[i];
	int ans = 0;
	FOR(i,1,n) {
		FOR(j,1,n) {
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(abs(a[i]-b[j]) <= 4) {
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
			}
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans;
}	
