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
#define F0R(i,n) for(int (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); (i)--)
#define int long long 

using namespace std;

const int MX = 205;
pair<pii,int> a[MX];
bool vis[MX];
int n,ans;

// returns distance square
inline int dist(const pii& a, const pii& b) {
	return (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}

void dfs(int node) {
	vis[node] = true;
	F0R(i,n) {
		if(i == node) continue;
		if(!vis[i] && dist(a[i].F, a[node].F) <= a[node].S*a[node].S) dfs(i);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");
	#define cin fin
	#define cout fout
	cin >> n;
	F0R(i,n) cin >> a[i].F.F >> a[i].F.S >> a[i].S;
	F0R(i,n) {
		MS(vis,false);
		dfs(i);
		int c = 0; F0R(i,n) c += vis[i];
		ans = max(ans, c);
	}
	cout << ans;
}	
