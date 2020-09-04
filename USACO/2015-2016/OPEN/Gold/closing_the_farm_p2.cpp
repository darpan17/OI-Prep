#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
vector<int> adj[MAXN];
bool ans[MAXN], pres[MAXN];
int root[MAXN], ranks[MAXN];
int n,m;

int getRoot(int node) {
	if(root[node] == node) return node;
	else return root[node] = getRoot(root[node]);
}

bool merge(int u, int v) {
	int r1 = getRoot(u);
	int r2 = getRoot(v);
	if(r1 == r2) return false;
	if(ranks[r1] >= ranks[r2]) {
		ranks[r1] += ranks[r2];
		root[r2] = r1;
	} else {
		ranks[r2] += ranks[r1];
		root[r1] = r2;
	}
	return true;
}

int main() {
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int u,v; scanf("%d%d",&u,&v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int perm[n];
	for(int i=0;i<n;i++) {
		scanf("%d",&perm[i]); --perm[i];
	}
	
	for(int i=0;i<n;i++) {
		root[i] = i; ranks[i] = 1;
	}
	
	int comps = 0;
	for(int i=n-1;i>=0;i--) {
		int node = perm[i];
		pres[node] = true; ++comps;
		for(int u:adj[node]) {
			if(!pres[u]) continue;
			else if(merge(u,node)) --comps;
		}
		if(comps == 1) ans[i] = true;
	}
	for(int i=0;i<n;i++) {
		puts(ans[i] ? "YES":"NO");
	}
}
