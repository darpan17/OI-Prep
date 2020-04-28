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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ifstream fin("moobuzz.in");
	ofstream fout("moobuzz.out");
	#define cin fin
	#define cout fout

	ll n; cin >> n;
	ll lo = 1, hi = 1e18, mid;
	while(lo <= hi) {
		mid = lo+hi+1ULL>>1ULL;
		ll s3 = mid/3, s5 = mid/5, s15 = mid/15;
		ll skip = s3+s5-s15;
		skip = max(skip, 0LL);
		ll num = mid-skip;
		if(num == n) {
			if(mid%3==0)--mid;
			cout << mid << "\n";
			return 0;
		}
		if(num > n) hi = mid-1;
		else lo = mid;
	}
}	
