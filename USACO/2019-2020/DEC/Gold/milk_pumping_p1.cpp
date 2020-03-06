#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,m;
const int MAXN = 1e3+5;
vector<pair<int,pair<int,int>>> adj[MAXN]; // {cost, flow}
int dist[MAXN];
int ff[MAXN];
int minflow = 1e18;

struct comp {
    bool operator () (const pair<int,pair<int,int>>& p1, const pair<int,pair<int,int>>& p2) {
        if(p1.second.first < p2.second.first) return true;
        if(p1.second.first == p2.second.first && p1.second.second > p2.second.second) return true;
        return false;
    }
};

void solve() {
    cin >> n >> m;
    int u,v,x,y;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> x >> y;
        u--; v--;
        adj[u].push_back({v,{x,y}});
        adj[v].push_back({u,{x,y}});
    }
    for(int i = 0; i < n; i++) dist[i] = 1e18;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, comp> pq;
    pq.push({0,{0,0}});
    dist[0] = 0;
    while(!pq.empty()) {
        int node = pq.top().first;
        pq.pop();
        for(auto& i:adj[node]) {
            if(i.second.first+dist[node] < dist[i.first]) {
                dist[i.first] = i.second.first+dist[node];
                ff[i.first] = i.second.second;
                pq.push({i.first,{dist[node],ff[node]}});
                minflow = min(minflow,ff[i.first]);
            } else if(i.second.first+dist[node] == dist[i.first] && i.second.second > ff[i.first]) {
                ff[i.first] = i.second.second; 
                pq.push({i.first,{dist[node],ff[node]}});
                minflow = min(minflow,ff[i.first]);
            }
        }
    } 
    double ans = (double)minflow/dist[n-1];
    ans = ans*1e6;
    cout << (int)ans << "\n";
}

int32_t main() {
    #ifdef LOCAL
    freopen("inp.txt","r",stdin);
    #else
    freopen("pump.in","r",stdin);
    freopen("pump.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
