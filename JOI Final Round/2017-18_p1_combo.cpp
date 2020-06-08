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
    const int MX = 2e5+5;
    const ll MOD = 1e9+7;
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        int n,k; cin >> n >> k;
        ll t[n]; F0R(i,n) cin >> t[i];
        vector<ll> segs;
        FOR(i,1,n-1) {
            segs.pb(t[i]-t[i-1]-1);
        }
        sort(all(segs));
        ll ans = n;
        F0R(i,n-k) ans += segs[i];
        cout << ans;
    }
