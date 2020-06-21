#include <bits/stdc++.h>

#define F0R(i,n) for(auto i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define ROF(i,a,b) for(auto i = (a); i >= (b); i--)
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>

using namespace std;

const int MAXN = 5e4+5;
int n,m,k;
int yum[MAXN];
vector<pii> adj[MAXN],adj2[MAXN]; // node, dist
int dist[MAXN],dist2[MAXN];
bool ans[MAXN];

void dijkstra1() {
	F0R(i,n-1)dist[i] = 1e9;
	
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push(make_pair(dist[n-1],n-1));

	while(!pq.empty()) {
		int node = pq.top().S;
		pq.pop();
		for(pii u : adj[node]) {
			if(dist[u.F] > dist[node]+u.S) {
				dist[u.F] = dist[node]+u.S;
				pq.push(make_pair(dist[u.F],u.F));
			}
		}
	}
}

void dijkstra2() {
	F0R(i,n-1)dist2[i] = 1e9;
	
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push(make_pair(dist2[n-1],n-1));

	while(!pq.empty()) {
		int node = pq.top().S;
		pq.pop();
		for(pii u : adj2[node]) {
			if(dist2[u.F] > dist2[node]+u.S) {
				dist2[u.F] = dist2[node]+u.S;
				pq.push(make_pair(dist2[u.F],u.F));
			}
		}
	}
}

signed main() {
	freopen("dining.in","r",stdin);
	freopen("dining.out","w",stdout);

	scanf("%lld%lld%lld",&n,&m,&k);
	F0R(i,m) {
		int u,v,d; scanf("%lld%lld%lld",&u,&v,&d);
		--u; --v;
		adj[u].pb(make_pair(v,d));
		adj[v].pb(make_pair(u,d));
	}
	F0R(i,n) yum[i] = -1;
	F0R(i,k) {
		int u,d; scanf("%lld%lld",&u,&d); --u;
		yum[u] = d;

	}

	dijkstra1();

	F0R(i,n) ans[i] |= (yum[i] >= 0);
	F0R(i,n) {
		if(yum[i] >= dist[i]*2) {
			F0R(j,n)ans[j] = true;
			break;
		} 
	}

	F0R(i,n-1) {
		for(pii u : adj[i]) {
			if(u.F == n-1) continue;
			adj2[i].pb(u);
		}
	}
	F0R(i,n-1) {
		if(yum[i] >= 0) {
			adj2[n-1].pb(make_pair(i,dist[i]-yum[i]));
		}
	}

	dijkstra2();

	F0R(i,n) ans[i] |= (dist2[i]<=dist[i]);

	F0R(i,n-1) printf("%lld\n",(int)ans[i]);
}
