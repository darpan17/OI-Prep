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
const int MX = 1005;
const ll MOD = 1e9+7;

ll dp[MX][MX];
pair<int,int> fc[MX],bc[MX];

inline ll dist(pair<int,int> a,pair<int,int> b) {
    ll res = 0;
    res = abs(a.F-b.F)*abs(a.F-b.F);
    res += abs(a.S-b.S)*abs(a.S-b.S);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ifstream fin("radio.in");
    ofstream fout("radio.out");
    #define cin fin
    #define cout fout
     
    int n,m; cin >> n >> m;
    cin >> fc[0].F >> fc[0].S >> bc[0].F >> bc[0].S;
    string fs,bs; cin >> fs >> bs;
    FOR(i,1,n) {
        char mov = fs[i-1];
        fc[i] = fc[i-1];
        if(mov == 'N') fc[i].S++;
        else if(mov == 'S') fc[i].S--;
        else if(mov == 'E') fc[i].F++;
        else fc[i].F--;
    }
    FOR(i,1,m) {
        char mov = bs[i-1];
        bc[i] = bc[i-1];
        if(mov == 'N') bc[i].S++;
        else if(mov == 'S') bc[i].S--;
        else if(mov == 'E') bc[i].F++;
        else bc[i].F--;
    }
    dp[0][0] = 0;
    F0R(i,n+1) {
        F0R(j,m+1) {
            if(i == 0 && j == 0) continue;
            dp[i][j] = dist(fc[i],bc[j]);
            ll minadd = LINF;
            if(i > 0 && j > 0) minadd = min(minadd,dp[i-1][j-1]);
            if(i > 0) minadd = min(minadd,dp[i-1][j]);
            if(j > 0) minadd = min(minadd,dp[i][j-1]);
            dp[i][j] += minadd;
        }
    }
    cout << dp[n][m];
}
