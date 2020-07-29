#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SZ(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define F0R(i,n) FOR(i,0,(n)-1)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

const ll MOD = 1e9+7;
const int MAXN = 1e6+5;
const int INF = 1e9+21;
const ll LINF = 1e18+5;
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
void IO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

ll dp[MAXN];

ll fxp(ll x,ll y,ll p = MOD){	
	if(y == 0) return 1;
	if(y == 1) return (x%p);
	ll res = 1;
	res *= fxp(x,y/2,p); res %= p;
	res *= res; res %= p;
	if(y&1) res *= x; res %= p;
	return res;
}

int main() {
	freopen("spainting.in","r",stdin);
	freopen("spainting.out","w",stdout);
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	ll tot = fxp(m,n);
	FOR(i,1,k-1) dp[i] = (dp[i-1]+fxp(m,i))%MOD;
	FOR(i,k,n) dp[i] = ((m*dp[i-1])%MOD-((m-1)*dp[i-k])%MOD)%MOD;
	// F0R(i,n+1) cout << dp[i] << " "; cout << endl;
	printf("%lld\n",(MOD+tot-(dp[n]-dp[n-1]))%MOD);
}
