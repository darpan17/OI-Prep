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

const int MX = 1e6+5;
const ll MOD = 1e9+7;
int n,k; 
int col[MX];
ll dp[MX][4];
vector<int> adj[MX];

ll dfs(int node,int node_col,int p,int p_col) {
	if(col[node]!=-1 && col[node]!=node_col)return 0;
	if(dp[node][node_col] != -1) return dp[node][node_col];
	
	dp[node][node_col] = 1;
	for(auto& u:adj[node]) {
		if(u==p) continue;
	
		ll r = 0;
		F0R(i,3) {
			if(node_col==i)continue;
			r += dfs(u,i,node,node_col);
			r %= MOD;
		}
	
		dp[node][node_col] *= r;
		dp[node][node_col]%= MOD;
	}
	return dp[node][node_col];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ifstream fin("barnpainting.in");
	ofstream fout("barnpainting.out");
	#define cin fin
	#define cout fout

	cin >> n >> k;
	F0R(i,n-1) {
		int u,v; cin >> u >> v; --u;--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	F0R(i,n) {
		col[i] = dp[i][0] = dp[i][2] = dp[i][1] = dp[i][3] = -1;
	}

	F0R(i,k) {
		int u,c; cin >> u >> c;--u;--c;
		col[u] = c;
	}

	ll res = 0;
	res += dfs(0,0,-1,-1); res %= MOD;
	res += dfs(0,1,-1,-1); res %= MOD;
	res += dfs(0,2,-1,-1); res %= MOD;
	cout << res;
}	
