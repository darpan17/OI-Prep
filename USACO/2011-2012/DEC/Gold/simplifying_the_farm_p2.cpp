/*
SOLUTION: number of minimum spanning trees is basically product of repeating edges
*/
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

const int MAXN = 4e4+5;
const ll MOD = 1e9+7;
int n,m;
int head[MAXN],ranks[MAXN];
ll fact[MAXN];
set<ll> s;
map<ll,ll> cnt,used;

ll nCr(ll n,ll r) {
	ll numer = fact[n];
	ll denom = fact[r]*fact[n-r];
	denom %= MOD;
	return (numer/denom)%MOD;
}

int getHead(int node) {
	if(head[node] == node) return node;
	else return head[node] = getHead(head[node]);
}

bool merge(int u,int v) {
	int hu = getHead(u),hv = getHead(v);
	if(hu == hv)return false;
	if(ranks[hu] > ranks[hv]) {
		head[hv] = hu;
		ranks[hu] += ranks[hv];
	} else {
		head[hu] = hv;
		ranks[hv] += ranks[hu];
	}
	return true;
}

void init() {
	fact[0] = 1;
	FOR(i,1,MAXN-1) {
		fact[i] = fact[i-1]*i;
		fact[i] %= MOD;
		head[i] = i;
		ranks[i] = 1;
	}	
}

int main() {
	init();
	cin >> n >> m;
	vector<pair<ll,pii>> edges(m);
	F0R(i,m) {
		cin >> edges[i].S.F >> edges[i].S.S >> edges[i].F;
		--edges[i].S.F; --edges[i].S.S;
	}
	sort(all(edges));
	ll len = 0, treecnt = 1;
	F0R(i,m) {
		bool b = merge(edges[i].S.F,edges[i].S.S);
		if(b) {
			++used[edges[i].F];
			s.insert(edges[i].F);
			len += edges[i].F;
		}
		++cnt[edges[i].F];
	}	
	for(auto& i:s) {
		treecnt *= nCr(cnt[i],used[i]);
		//cout << " treecnt = " << treecnt << " i = " << i << " cnt[i] = " << cnt[i] << " used[i] = " << used[i] << endl;
		treecnt %= MOD;
	}
	cout << len << " " << treecnt;
}	
