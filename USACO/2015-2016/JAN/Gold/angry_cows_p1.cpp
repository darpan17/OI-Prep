#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x) memset(x,a,sizeof(x))
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

const int MX = 5e4+5;
int n;
ll dpleft[MX],dpright[MX];
ll pos[MX];
ld ans = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//~ ifstream fin("angry.in");
	//~ ofstream fout("angry.out");
	//~ #define cin fin
	//~ #define cout fout
	cin >> n;
	FOR(i,1,n) cin >> pos[i];
	sort(pos+1,pos+1+n);
	dpleft[1] = 0;
	FOR(i,2,n) dpleft[i] = max(dpleft[i-1]+1,pos[i]-pos[i-1]);
	dpright[n] = 0;
	ROF(i,n-1,1) dpright[i] = max(dpright[i+1]+1,pos[i+1]-pos[i]);
	FOR(i,2,n) ans = min(ans,(ld)max((ld)((pos[i]-pos[i-1])/2.0),(ld)max(dpleft[i-1],dpright[i])+1.0));
	cout.precision(1);
	cout << fixed;
	cout << ans;
}	
