#include <bits/stdc++.h>
#include "game.h"
using namespace std;

const int MAXN = 1505;
int root[MAXN];
int edgecnt[MAXN][MAXN];
int n;

int findRoot(int node) {
	if(root[node] == node) return node;
	return root[node] = findRoot(root[node]);
}

bool sameComp(int u, int v) {
	return findRoot(u) == findRoot(v);
}

void unite(int u, int v) {
	if(u > v) swap(u,v);
	u = findRoot(u);
	v = findRoot(v);
	for(int i=0;i<n;i++) {
		if(root[i] == v) root[i] = u;
	}
	for(int i=0;i<n;i++) {
		if(i == u) continue;
		edgecnt[i][u] += edgecnt[i][v];
		edgecnt[u][i] += edgecnt[v][i];
	}
}

void initialize(int _n) {
	n = _n;
	for(int i=0;i<n;i++) root[i] = i;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			edgecnt[i][j] = 1;
		}
	}
}


int hasEdge(int u, int v) {
	if(sameComp(u,v)) return 0;
	u = findRoot(u); v = findRoot(v);
	if(edgecnt[u][v] == 1) {
		unite(u,v);
		return 1;
	} else {
		--edgecnt[u][v];
		--edgecnt[v][u];
		return 0;
	}
}
