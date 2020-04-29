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
	ifstream fin("homework.in");
	ofstream fout("homework.out");
	#define cin fin
	#define cout fout
	int n; cin >> n;
	ll a[n]; F0R(i,n) cin >> a[i];
	ll minsofar[n];
	minsofar[n-1] = a[n-1];
	ROF(i,n-2,0)minsofar[i] = min(minsofar[i+1],a[i]);
	ll suf[n];
	suf[n-1] = a[n-1];
	ROF(i,n-2,0)suf[i] = suf[i+1]+a[i];
	vector<int> ans; double maxavg = 0.0;
	F0R(i,n-1) {
		double temp = ((suf[i+1]-minsofar[i+1])*1.0)/(ld)(n-i-2);
		if(temp > maxavg) {
			maxavg = temp;
			ans.clear();
			ans.pb(i+1);
		} else if(temp == maxavg) ans.pb(i+1);
	}
	F0R(i,SZ(ans)) cout << ans[i] << "\n";
}
