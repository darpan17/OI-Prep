/*
SOLUTION : same as edi
*/



#include <bits/stdc++.h>
using namespace std;

#define F0R(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define F first
#define S second

const int MAXN = 1e5+5;
int n,m;
int t[MAXN];
pair<int,int> queryData[MAXN];
int c[MAXN];
vector<int> adj[MAXN];
vector<int> ord;
vector<pair<int,int>> store[MAXN];
pair<int,int> tym[MAXN];
vector<int> todo[MAXN]; // contains query indices
bool ans[MAXN];
int timer;

// whether u is an ancestor of v
bool isAnc(int u, int v) {
	return (tym[u].F <= tym[v].F && tym[u].S >= tym[v].S);
}

void dfs1(int node, int p) {
	tym[node].F = timer++;
	for(int u : adj[node]) {
		if(u == p) continue;
		dfs1(u,node);
	}
	tym[node].S = timer-1;
}
void dfs2(int node, int p) {
	store[t[node]].push_back({node,ord.size()});
	ord.push_back(node);
	
	if(todo[node].size() > 0) {
		for(int query: todo[node]) {
			if(store[c[query]].size() > 0) {
				int farm = store[c[query]].back().F;
				int dep = store[c[query]].back().S;

				if(farm == node) ans[query] = true;
				else {
					assert(queryData[query].F == node || queryData[query].S == node);
					int otherFarm = queryData[query].F+queryData[query].S-node;

					int farmAtReqDep = ord[dep+1]; // potential lca

					// this means it lies on path of [node,lca]
					// if farmAtReqDep is lca, that means farm is not lca, hence ans will be false
					// but if farmAtReqDep is not lca, that means farm is lca
					if(!isAnc(farmAtReqDep,otherFarm)) {
						// cout << "farmAtReqDep = " << farmAtReqDep << " farm = " << farm << endl;
						ans[query] = true;
					}

				}
			}
		}
	}

	for(int u : adj[node]) if(u != p) dfs2(u,node);
	store[t[node]].pop_back();
	ord.pop_back();
}

int main() {
	freopen("milkvisits.in","r",stdin);
	freopen("milkvisits.out","w",stdout);
	scanf("%d%d",&n,&m);
	F0R(i,n) scanf("%d",&t[i]);
	F0R(i,n-1) {
		int u,v; scanf("%d%d",&u,&v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	F0R(i,m) {
		int u,v,type; scanf("%d%d%d",&queryData[i].F,&queryData[i].S,&c[i]);
		--queryData[i].F; --queryData[i].S;
		todo[queryData[i].F].push_back(i);
		todo[queryData[i].S].push_back(i);
	}
	dfs1(0,-1);
	dfs2(0,-1);
	F0R(i,m) printf("%d",(int)ans[i]);
}
