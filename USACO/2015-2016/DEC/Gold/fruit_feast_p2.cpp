#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#define MS(x,a) memset((x), (a), sizeof(x))
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

const int INF = 1e9+2;
const ll LINF = 1e18+2;
const int MX = 5e6+5;
const ll MOD = 1e9+7;

bool dp[MX][2];

int main() {
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,a,b; cin >> n >> a >> b;
    dp[0][0] = true;
    FOR(i,1,n) {
        if(i-a >= 0) dp[i][0] |= dp[i-a][0];
        if(i-b >= 0) dp[i][0] |= dp[i-b][0];
        dp[i/2][1] |= dp[i][0];
    }
    FOR(i,1,n) { 
        if(i-a >= 0) dp[i][1] |= dp[i-a][1];
        if(i-b >= 0) dp[i][1] |= dp[i-b][1];
    }
    int ans = 0; 
    FOR(i,1,n) if(dp[i][0]|dp[i][1]) ans = i;
    cout << ans;
}
