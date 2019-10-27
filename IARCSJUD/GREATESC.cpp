#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define ff first
#define ss second
#define pb push_back

using namespace std;

vi g[3505];
bool vis[3505];
int dist[3505];
int n,m;

void dijkstra(int src,int dst){
	FOR(i,n) dist[i] = 1 << 20;
	set<pii> s;
	dist[src] = 0;
	s.insert({0,src});
	int node,d;
	while(!s.empty()){
		node = s.begin()->ss;
		d = s.begin()->ff;
		s.erase(s.begin());
		for(auto& i:g[node]){
			if(!vis[i]){
				if(dist[i] > d+1){
					s.erase({dist[i],i});
					dist[i] = d+1;
					s.insert({dist[i],i});
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int u,v;
	FOR(i,m){
		cin >> u >> v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	int src,dst; cin >> src >> dst;
	src--; dst--;
	dijkstra(src,dst);
	if(dist[dst] == (1 << 20)) cout << 0;
	else cout << dist[dst];
	return 0;
}
