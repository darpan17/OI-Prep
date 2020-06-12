#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x,a) memset((x),(a),sizeof(x)) 
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

const int MAXN = 5e5+5;
pll a[MAXN];
ll pre[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	FOR(i,1,n) cin >> a[i].F >> a[i].S;
	sort(a+1,a+1+n);
	FOR(i,1,n) pre[i] = pre[i-1]+a[i].S;
	ll l = 0,sl = 0,ans = 0;
	FOR(i,1,n) {
		ll v = a[i].F-pre[i-1];
		l = max(l,v);
		v = pre[i]-a[i].F;
		ans = max(ans,v+l);
	}
 	cout << ans;
}	
