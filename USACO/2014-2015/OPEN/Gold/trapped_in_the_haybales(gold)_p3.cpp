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
	ifstream fin("trapped.in");
	ofstream fout("trapped.out");
	#define cin fin
	#define cout fout
	int n; cin >> n;
	ll stren[n],pos[n],l[n],r[n];
	bool broken[n];
	MS(broken,false);
	MS(stren,0);
	MS(pos,0);
	MS(l,0);
	MS(r,0);
	F0R(i,n) cin >> stren[i] >> pos[i];
	l[0] = 0;
	FOR(i,1,n-1) {
		if(pos[i]-pos[i-1]+l[i-1] > stren[i]) {
			broken[i] = true;
			l[i] = l[i-1]+pos[i]-pos[i-1];
		}
	}
	r[n-1] = 0;
	ROF(i,n-2,0) {
		if(broken[i]) {
			r[i] = r[i+1]+pos[i+1]-pos[i];
			continue;
		}
		if(pos[i+1]-pos[i]+r[i+1] > stren[i]) {
			broken[i] = true;
			r[i] = r[i+1]+pos[i+1]-pos[i];
		}
	}
	/*l[0] = 0;
	FOR(i,1,n-1) {
		if(broken[i]) {
			l[i] = l[i-1]+pos[i]-pos[i-1];
			continue;
		}
		if(pos[i]-pos[i-1]+l[i-1] > stren[i]) {
			broken[i] = true;
			l[i] = l[i-1]+pos[i]-pos[i-1];
		}
	}*/
	ll lastbloc = -1;
	ll ans = 0;
	F0R(i,n) {
		if(!broken[i]) {
			if(lastbloc != -1) {
				ans += pos[i]-pos[lastbloc];
			}
			lastbloc = i;
		}
	}
	cout << ans;
}	

