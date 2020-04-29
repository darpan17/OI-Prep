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
#define pss pair<string,string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");
	#define cin fin
	#define cout fout
	int n; cin >> n;
	pss a[n]; F0R(i,n) cin >> a[i].F >> a[i].S;
	map<pss,int> cnt;
	F0R(i,n) {
		++cnt[mp(a[i].F.substr(0,2), a[i].S)];
	}
	int ans = 0;
	F0R(i,n) {
		if(a[i].F.substr(0,2) == a[i].S) continue;
		ans += cnt[mp(a[i].S, a[i].F.substr(0,2))];
	}
	ans /= 2;
	cout << ans;
}	
