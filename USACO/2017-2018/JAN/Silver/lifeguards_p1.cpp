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

bool comp(pll a,pll b) {
	if(a.F < b.F)return true;
	else if(a.F == b.F && a.S < b.S) return true;
	return false;
}

int main() {
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");
	#define cin fin
	#define cout fout
	int n; cin >> n;
	vector<pll> a(n); F0R(i,n)cin >> a[i].F >> a[i].S;
	sort(all(a),comp);
	ll tt = 0;
	tt = a[0].S-a[0].F;
	FOR(i,1,n-1) {
		tt += max(0LL,a[i].S-max(a[i-1].S,a[i].F));
	}
	ll mt = 1e18;
	FOR(i,1,n-2) {
		ll r = min(a[i+1].F,a[i].S);
		ll l = max(a[i-1].S,a[i].F);
		mt = min(mt,max(0LL,r-l));
	}
	mt = min(mt,max(0LL,min(a[1].F,a[0].S)-a[0].F));
	mt = min(mt,max(0LL,a[n-1].S-max(a[n-1].F,a[n-2].S)));
	cout << tt-mt;
}	
