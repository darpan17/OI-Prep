/*
SOLUTION: Create edges b/w all pairs of cows.
Then create a MST and find out the wt of the largest edge used.
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
int head[MX],ranks[MX];

int getHead(int node) {
	if(head[node] == node)return node;
	else return getHead(head[node]);
}

bool merge(int u,int v) {
	u = getHead(u); v = getHead(v);
	if(u == v)return false;
	if(ranks[u] > ranks[v]) {
		ranks[u] += ranks[v];
		head[v] = u;
	} else {
		ranks[v] += ranks[u];
		head[u] = v;
	}
	return true;
}

inline ll cost(pii& x,pii& y) {
	ll dx = x.F-y.F;
	ll dy = x.S-y.S;
	return (dx*dx+dy*dy);
}

int main() {
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");
	#define cin fin
	#define cout fout
	int n; cin >> n;
	pii a[n]; F0R(i,n)cin >> a[i].F >> a[i].S;
	F0R(i,n) {
		head[i] = i; ranks[i] = 1;
	}
	vector<pair<ll,pii>> edges;
	F0R(i,n) {
		FOR(j,i+1,n-1) {
			edges.pb(mp(cost(a[i],a[j]),mp(i,j)));
		}
	}
	sort(all(edges));
	ll ans = 0;
	for(auto& e:edges) {
		if(merge(e.S.F,e.S.S)) {
			ans = e.F;
		}
	}
	cout << ans;
}	
