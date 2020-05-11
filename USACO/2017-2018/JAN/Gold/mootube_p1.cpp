/*
SOLUTION: Saw edi (like an idiot). 
Answer queries offline after sorting both edges and queries in decreasing order of weight.
ALWAYS USE COMPARISON BY RANK IN DSU!!
without comparsion by rank, test case 8 TLEs, with comparison, passes in 160ms.
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
#define F0R(i,n) for(int (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); (i)--)

using namespace std;

const int MX = 2e6+5; 
int head[MX],ranks[MX];
int ans[MX];

int findhead(int node) {
	if(head[node] == node) return node;
	return findhead(head[node]);
}

void merge(int u,int v) {
	u = findhead(u); v = findhead(v);
	if(ranks[v] > ranks[u]) {
		head[u] = v;
		ranks[v] += ranks[u];
	} else {
		head[v] = u;
		ranks[u] += ranks[v];
	}
}

bool comp(pair<pii,ll> u,pair<pii,ll> v) {
	return (u.S > v.S);
}

bool comp1(pair<pll,int> a,pair<pll,int> b) {
	return (a.F.F > b.F.F);
}

int main() {
	ifstream fin("mootube.in");
	ofstream fout("mootube.out");
	#define cin fin
	#define cout fout
	int n,q; cin >> n >> q;
	FOR(i,1,n) {
		head[i] = i; ranks[i] = 1;
	}
	vector<pair<pii,ll>> edges(n-1);
	F0R(i,n-1) cin >> edges[i].F.F >> edges[i].F.S >> edges[i].S;
	sort(all(edges),comp); 
	vector<pair<pll,int>> qr(q); F0R(i,q) cin >> qr[i].F.F >> qr[i].F.S;
	F0R(i,q)qr[i].S = i;
	sort(all(qr),comp1);
	int ei = 0;
	F0R(i,q) {
		while(ei < n && edges[ei].S >= qr[i].F.F) {
			merge(edges[ei].F.F,edges[ei].F.S);
			++ei;
		}
		ans[qr[i].S] = ranks[findhead(qr[i].F.S)];
	}
	F0R(i,q)cout << ans[i]-1 << "\n";
}	
