#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

const int MAXN = 3e5+5;

vector<pair<int,int>> path, temp;
vector<int> adj[MAXN];
int n,a,b;
pair<int,int> curEdge;


void dfs(int node, int p) {
	if(!path.empty()) return;
	if(node == b) {
		path = temp;
		return;
	}
	
	for(auto& u:adj[node]) {
		if(u == p) continue;
		temp.push_back({u,node});
		dfs(u,node);
		temp.pop_back();
	}
}

int dfs1(int node, int p) {
	int res = 0;
	vector<int> c;
	for(auto& u: adj[node]) {
		if(u == p || (node == curEdge.F && u == curEdge.S) || (u == curEdge.F && node == curEdge.S)) continue;
		c.push_back(dfs1(u,node));
	}
	sort(c.rbegin(), c.rend());
	for(int i=0;i<c.size();i++) res = max(res, c[i]+i+1);
	return res;
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for(int i=0;i<n-1;i++) {
		int u,v;
		scanf("%d%d", &u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	// figure out path
	dfs(a,-1);
	
	// figure out optimal split edge
	int lo = 0, hi = path.size()-1, mid;
	int ld = 0;
	
	while(lo <= hi) {
		mid = lo+hi>>1;
		curEdge = path[mid];
		int resa = dfs1(a,-1);
		int resb = dfs1(b,-1);
		if(resa <= resb) {
			lo = mid+1;
			ld = mid;
		} else {
			hi = mid-1;
		}
	}
	
	int ans = 1e9;
	int testIdx = ld;
	if(testIdx >= 0 && testIdx < path.size()) {
		curEdge = path[testIdx];
		ans = min(ans, max(dfs1(a,-1), dfs1(b,-1)));
	}
	--testIdx;
	if(testIdx >= 0 && testIdx < path.size()) { 
		curEdge = path[testIdx];
		ans = min(ans, max(dfs1(a,-1), dfs1(b,-1)));
	}
	testIdx += 2;
	if(testIdx >= 0 && testIdx < path.size()) {
		curEdge = path[testIdx];
		ans = min(ans, max(dfs1(a,-1), dfs1(b,-1)));
	}
	
	printf("%d",ans);
}
/*

6 2 1
1 2
2 3
2 4
1 5
5 6

10 1 2
1 2
2 5
1 3
1 4
4 6
6 7
3 8
3 9
3 10


17 1 2
1 3
1 4
4 6
6 7
3 8
3 9
3 10
1 13
13 5
13 11
13 12
13 14
14 15
15 16
15 17
14 2

*/

