#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SZ(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define F0R(i,n) FOR(i,0,(n)-1)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

const ll MOD = 1e9+7;
const int MAXN = 2e5+5;
const int INF = 1e9+21;
const ll LINF = 1e18+5;
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
void IO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int n,m;
vi euler;
int a[MAXN];
int focc[MAXN],foccidx[MAXN];
bool ans[MAXN];
vi adj[MAXN];
set<int> ainds[MAXN];

struct Query {
	int l,r,t,idx;
	Query() { l = r = t = idx = 0; }
	Query(int _l, int _r, int _t, int _idx) { l = _l; r = _r; t = _t; idx = _idx; }
	
	bool operator <(const Query& other) {
		if(focc[l] < focc[other.l]) return true;
		else if(focc[l] == focc[other.l] && focc[r] < focc[other.r]) return true;
		return false;
	}
};

void dfs(int node, int p) {
	euler.pb(node);
	if(focc[node] == -1) focc[node] = SZ(euler)-1;
	bool f = true;
	for(int u : adj[node]) {
		if(u == p) continue;
		if(!f) euler.pb(node);
		else f = false;
		dfs(u,node);
		euler.pb(-node);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	F0R(i,n) scanf("%d",&a[i]);
	F0R(i,n-1) {
		int u,v; scanf("%d%d",&u,&v);
		--u; --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<Query> qa(m);
	F0R(i,m) {
		scanf("%d%d%d",&qa[i].l,&qa[i].r,&qa[i].t);
		--qa[i].l; --qa[i].r;
		qa[i].idx = i;
	}

	dfs(0,-1);
	sort(all(qa));
	queue<pii> qu;
	int qptr = 0;

	int esz = SZ(euler);
	F0R(i,esz) {
		if(focc[euler[i]] == i) {
			while(qptr < m && qa[qptr].l == euler[i]) {
				ainds[a[euler[i]]].insert()
			}
		}
	}
}
