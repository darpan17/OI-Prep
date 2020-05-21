#include <bits/stdc++.h>
#include "cave.h"

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
/*
int tryCombination(int s[]) {
	cout << "combo: ";
	F0R(i,4) cout << s[i] << " ";
	cout << endl;
	int x; cin >> x;
	return x;
}

void answer(int s[],int d[]) {
	cout << "s = "; F0R(i,4) cout << s[i] << " "; cout << endl;
	cout << "d = "; F0R(i,4) cout << d[i] << " "; cout << endl;
}
*/
void exploreCave(int n) {
	int s[n] = {},d[n] = {};
	int sw[n] = {},fixed[n] = {};
	set<int> notdone;
	F0R(i,n)notdone.insert(i);
	int cur = tryCombination(s);
	while(cur != -1 && !notdone.empty()) {
		for(auto i:notdone) {
			s[i] ^= 1;
			int now = tryCombination(s);
			if(now == -1) {
				cur = -1; break;
			}
			if(now == cur)continue;
			if(now < cur) {
				d[i] = now;
				sw[i] = s[i]^1;
				s[i] ^= 1;
				notdone.erase(i);
				fixed[i] = true;
			} else {
				d[i] = cur;
				sw[i] = s[i];
				notdone.erase(i);
				cur = now;
				fixed[i] = true;
			}
		}
	}
	int x;
	F0R(i,n) {
		if(!fixed[i]) {
			s[i] ^= 1;
			x = tryCombination(s);
			s[i] ^= 1;
			sw[i] = s[i];
			d[i] = x;
			fixed[i] = true;
		}
	}
	answer(sw,d);
}
/*
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	exploreCave(4);
}	
*/
