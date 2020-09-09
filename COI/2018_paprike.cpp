#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int MAXN = 1e5+5;
vector<int> adj[MAXN];
int dp[MAXN];
ll a[MAXN], sum[MAXN];
int n;
ll k;

void dfs(int node, int p) {
	sum[node] = a[node];
	vector<pair<ll,int>> c;
	for(auto& u: adj[node]) {
		if(u == p) continue;
		dfs(u,node);
		c.push_back({sum[u], dp[u]});
	}
	
	sort(c.begin(), c.end());
	for(int i=0;i<c.size();i++) {
		if(sum[node]+c[i].F <= k) {
			sum[node] += c[i].F;
			dp[node] += c[i].S;
		} else {
			dp[node] += c[i].S+1;
		}
	}
}

int main() {
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<n-1;i++) {
		int u,v; scanf("%d%d",&u,&v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0,-1);
	printf("%d",dp[0]);
}

/*
5 5
1 2 3 4 5
1 2
2 3
3 4
4 5

10 10
3 4 2 3 7 1 4 1 5 2
1 2
2 4
5 2
6 3
3 1
6 7
9 7
8 6
8 10


6 9
5 4 1 3 3 3
3 1
3 5
4 3
4 2
2 6
*/
