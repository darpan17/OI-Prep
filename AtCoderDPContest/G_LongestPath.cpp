#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)
#define vi vector<int>
#define pb push_back

using namespace std;

const int MAXN = 100006;
int dp[MAXN];
vi par[MAXN];
bool vis[MAXN];

void dfs(int node){
	if(par[node].empty()) dp[node] = 0;
	for(auto i:par[node]){
		if(dp[i] != INT_MIN) dp[node] = max(dp[node],dp[i]+1);
		else{
			dfs(i);
			dp[node] = max(dp[node],dp[i]+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m; cin >> n >> m;
	int x,y;
	while(m--){
		cin >> x >> y;
		x--; y--;
		par[y].pb(x);
	}
	FOR(i,n) dp[i] = INT_MIN;
	FOR(i,n){
		dfs(i);
	}
	int ans = 0;
	FOR(i,n) ans = max(ans,dp[i]);
	cout << ans;
	return 0;
}
