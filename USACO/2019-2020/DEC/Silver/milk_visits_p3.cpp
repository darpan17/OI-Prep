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

const int MX = 1e5+5;
vector<int> adj[MX];
char col[MX];
int comp[MX], num;

void dfs(int node,int p) {
	comp[node] = num;
	for(int& u:adj[node]) if(u!=p && col[u] == col[node]) dfs(u,node);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ifstream fin("milkvisits.in");
	ofstream fout("milkvisits.out");
	#define cin fin
	#define cout fout
	int n,m; cin >> n >> m;
	string str; cin >> str;
	F0R(i,n) col[i] = str[i];
	F0R(i,n-1) {
		int u,v; cin >> u >> v;
		--u; --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	F0R(i,n) comp[i] = -1;
	F0R(i,n) if(comp[i] == -1) ++num, dfs(i,-1);

	while(m--) {
		int u,v; char c; cin >> u >> v >> c;
		--u; --v;
		if(col[u] == c) cout << 1;
		else cout << (comp[u] != comp[v]);
	}
}	
