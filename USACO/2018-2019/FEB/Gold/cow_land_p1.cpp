/*
SOLUTION: do a euler tour of the tree and build segtree on it
utilize the property that x^x = 0
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
ll seg[11*MX],a[MX];
int focc[MX];
vector<int> euler;
vector<int> adj[MX];
vector<int> pts[MX];

void dfs(int node,int p) {
	euler.pb(a[node]);
	pts[node].pb(SZ(euler)-1);
	if(focc[node] == -1) focc[node] = SZ(euler)-1;
	for(auto& u:adj[node]) {
		if(u == p)continue;
		dfs(u,node);
	}
	euler.pb(a[node]);
	pts[node].pb(SZ(euler)-1);
}

void build(int node,int ss,int se) {
	if(ss > se) return;
	if(ss == se) {
		seg[node] = euler[ss];
		return;
	} 
	int mid = ss+se >> 1;
	build(node*2+1,ss,mid);
	build(node*2+2,mid+1,se);
	seg[node] = seg[2*node+1]^seg[2*node+2];
}

void update(int node,int ss,int se,int idx,ll val) {
	if(ss > se || idx > se || idx < ss) return;
	if(ss == se && ss == idx) {
		seg[node] = val;
		return;
	}
	int mid = ss+se >> 1;
	update(node*2+1,ss,mid,idx,val);
	update(node*2+2,mid+1,se,idx,val);
	seg[node] = seg[2*node+1]^seg[2*node+2];
}

ll query(int node,int ss,int se,int qs,int qe) {
	if(ss > se || qs > se || qe < ss) return 0LL;
	if(ss >= qs && se <= qe) return seg[node];
	int mid = ss+se >> 1;
	ll q1 = query(node*2+1,ss,mid,qs,qe);
	ll q2 = query(node*2+2,mid+1,se,qs,qe);
	return (q1^q2);
}

int main() {
	ifstream fin("cowland.in");
	ofstream fout("cowland.out");
	#define cin fin
	#define cout fout
	// freopen("C.cpp","r",stdin);
	// freopen("D.cpp","w",stdout);
	int n,q; cin >> n >> q;
	FOR(i,1,n) cin >> a[i];
	F0R(i,n-1) {
		int u,v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	F0R(i,n+1)focc[i] = -1;
	dfs(1,-1);
	int esz = SZ(euler);
	build(0,0,esz-1);

    // for(auto i:euler) cout << i << " "; cout << endl;
    // FOR(i,1,n) cout << focc[i] << " "; cout << endl;
	// cout << "BUILD DONE!" << endl;

	
	while(q--) {
		int t; cin >> t;
		if(t == 1) {
			int u; ll val; cin >> u >> val;
			for(auto& i:pts[u]) {
				update(0,0,esz-1,i,val);
			}
		} else {
			int x,y; cin >> x >> y;
			x = focc[x]; y = focc[y];
			// cout << "x = " << x << " y = " << y << endl;


			if(x > y) swap(x,y);
			cout << query(0,0,esz-1,x,y) << "\n";
		}
	}
}
