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
int n,m;
vector<int> euler;
vector<pii> cowc; // {H,G} count
int focc[MX];
string cowt;
vector<int> adj[MX];

void dfs(int node,int p) {
	euler.pb(node);
	pii toins = cowc.back();
	if(cowt[node]=='G')++toins.S; else ++toins.F;
	cowc.pb(toins);
	if(focc[node] == -1) focc[node] = SZ(euler)-1;
	bool leaf = true;
	for(int& i: adj[node]) {
		if(i == p)continue;
		dfs(i,node);
		euler.pb(node);
		toins = cowc.back();
		if(cowt[node]=='G')--toins.S; else --toins.F;
		cowc.pb(toins);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	// ifstream fin("milkvisits.in");
	// ofstream fout("milkvisits.out");
	// #define cin fin
	// #define cout fout
	cin >> n >> m >> cowt;
	F0R(i,n-1) {
		int u,v; cin >> u >> v;
		--u;--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	MS(focc,-1);
	cowc.pb({0,0});
	euler.pb(-1);
	dfs(0,-1);
	while(m--) {
		int u,v; char c; cin >> u >> v >> c;
		--u; --v;
		// cout << "u = " << u+1 << " v = " << v+1 << endl;
		int fu = focc[u],fv = focc[v];
		// cout << "focc[u] = " << focc[u] << " focc[v] = " << focc[v] << endl;
		if(fu > fv)swap(fu,fv);
		int hc = cowc[fv].F-cowc[fu-1].F;
		int gc = cowc[fv].S-cowc[fu-1].S;
		// cout << "hc = " << hc << " gc = " << gc << endl;
		if(c == 'H' and hc > 0) cout << 1;
		else if(c == 'G' and gc > 0) cout << 1;
		else cout << 0;
	}
}	
