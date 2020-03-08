#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    double a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    double dp[n+5][n+5];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) dp[i][j] = dp[i-1][j]*(1-a[i]);
            else dp[i][j] = dp[i-1][j-1]*a[i]+dp[i-1][j]*(1-a[i]);
        }
    }
    double ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i > n-i)ans += dp[n][i];
    }
    cout << fixed << setprecision(15) << ans;
}

int32_t main() {
    #ifdef LOCAL
    freopen("inp.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
