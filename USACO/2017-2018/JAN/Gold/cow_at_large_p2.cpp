/*
SOLUTION:if distance from leaf is less than equal to distance from the root, 
this node can be the leaf itself. Find the MINIMUM distance of a leaf from the node. 
If the distance is less than equal to distance from root, mark that node as leaf. 
Finally count all the leaves.
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

const int MX = 1e5+5;
int ans;
vector<int> adj[MX];
int ldist[MX];
bool leaf[MX];

void dfs(int node,int p,int dep) {
	int maxdist = 1e8;
	bool l = true;
	for(auto& u:adj[node]) {
		if(u == p)continue;
		l = false;
		dfs(u,node,dep+1);
		maxdist = min(maxdist,ldist[u]+1);
	}
	if(l) ldist[node] = 0;
	else ldist[node] = maxdist;
	if(l || maxdist <= dep) { leaf[node] = true; }
}

void dfs1(int node,int p) {
	if(leaf[node]) { ++ ans; return; }
	for(auto& u:adj[node]) {
		if(u == p)continue;
		dfs1(u,node);
	}
}

int main() {
	ifstream fin("atlarge.in");
	ofstream fout("atlarge.out");
	#define cin fin
	#define cout fout
	int n,r; cin >> n >> r; --r;
	F0R(i,n-1) {
		int u,v; cin >> u >> v;
		--u; --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(r,-1,0);
	dfs1(r,-1);
	cout << ans;
}	
