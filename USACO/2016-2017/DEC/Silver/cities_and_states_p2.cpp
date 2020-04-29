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

int h(string& x) {
	return (x[0]*221+x[1]*122);
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");
	#define cin fin
	#define cout fout
	int n; cin >> n;
	multiset<pair<int,int>> s;
	F0R(i,n) {
		string a,b; cin >> a >> b;
		a = a.substr(0,2);
		s.insert(mp(h(a),h(b)));
	}
	int ans = 0;
	while(!s.empty()) {
		pii temp = *s.begin();
		if(temp.F==temp.S) { s.erase(s.begin()); continue; } 
		swap(temp.F, temp.S);
		int lol = s.count(temp);
		ans += lol*(lol+1) >> 1;
		s.erase(temp);
		s.erase(s.begin());
	}
	cout << ans;
}	
