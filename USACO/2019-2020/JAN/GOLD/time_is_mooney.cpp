#include <bits/stdc++.h>
using namespace std;
#define F0R(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)
#define int long long
#define F first
#define S second
bool adj[1005][1005];
int dp[1005], tempDP[1005];
signed main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n,m,c; scanf("%lld%lld%lld",&n,&m,&c);
    int a[n]; F0R(i,n) scanf("%lld",&a[i]);
    vector<pair<int,int>> edges;
    F0R(i,m) {
        int u,v; scanf("%lld%lld",&u,&v);
        --u; --v;
        edges.push_back({u, v});
    }
    
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int ans = 0;
    FOR(tym,1,1000) {
        F0R(i,n) tempDP[i] = dp[i];
        F0R(i,n) dp[i] = -1;
        for(auto e : edges) {
            if(tempDP[e.F] >= 0)dp[e.S] = max(dp[e.S], tempDP[e.F]+a[e.S]);
        }
        ans = max(ans, dp[0]-c*tym*tym);
        
    }
    printf("%lld",ans);
}
