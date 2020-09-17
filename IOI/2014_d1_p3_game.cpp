#include <bits/stdc++.h>
#include "game.h"
using namespace std;

const int MAXN = 1505;
int el, comps;
bool done[MAXN];

void initialize(int n) {
	el = (n*(n-1))/2;
	comps = n;
}

int hasEdge(int u, int v) {
	int res;
	if(!done[u]&!done[v]) {
		done[u] = done[v] = true;
		res = 1;
	} else if(el == comps-1) {
		res = 1;
	} else {
		res = 0;
	}
	if(res == 1) --comps;
	--el;
	return res;
}

