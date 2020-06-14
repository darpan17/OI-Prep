#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>

#define ll long long int
#define F0R(i,n) for(auto i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define ROF(i,a,b) for(auto i = (a); i >= (b); i--)
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vv vector
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define int long long 

using namespace std;

const int MAXN = 1005;
vector<pair<int,pii>> adj[MAXN];
pii dp[MAXN];

signed main() {
	ifstream fin("pump.in");
	ofstream fout("pump.out");
	#define cin fin
	#define cout fout
	int n,m; cin >> n >> m;
	F0R(i,m) {
		int u,v,cost,flow; cin >> u >> v >> cost >> flow;
		--u; --v;
		adj[u].pb(make_pair(v,make_pair(flow,cost)));
		adj[v].pb(make_pair(u,make_pair(flow,cost)));
	}
	F0R(i,n) dp[i] = make_pair(-10000000,10000000);
	dp[0] = {1000000,0};
	queue<pair<int,pii>> q;
	q.push(make_pair(0,dp[0]));
	while(!q.empty()) {
		int node = q.front().F;
		q.pop();
		for(auto u:adj[node]) {
			if(u.F == 0) continue;
			pii newPath = make_pair(min(dp[node].F, u.S.F), dp[node].S + u.S.S);
			if(((newPath.F * 1000000)/newPath.S) > ((dp[u.F].F * 1000000)/dp[u.F].S)) {
				dp[u.F] = newPath;
				q.push(make_pair(u.F,newPath));
			} 
		}
	}
	cout << ((dp[n-1].F * 1000000)/ dp[n-1].S);
	cout << endl;
}
