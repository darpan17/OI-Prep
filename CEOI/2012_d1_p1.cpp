#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>

#define ll long long int
#define F0R(i,n) for(auto i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define ROF(i,a,b) for(auto i = (a); i >= (b); i--)
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vv vector
#define F first
#define S second
#define pb push_back
#define vi vector<int>

using namespace std;

const int MAXM = 1e6+5;
const int MAXN = 1e5+5;
int n,d,m;
pii a[MAXM];
vi ans[MAXN];

bool valid(int machines) {
	int mIdx = 1;
	queue<pii> q;
	FOR(i,1,n)ans[i].clear();
	FOR(i,1,n) {
		while(mIdx <= m && a[mIdx].F <= i) {
			q.push(a[mIdx]);
			mIdx++;
		}
		while(!q.empty() && ans[i].size() < machines) {
			if(q.front().F+d < i)return false;
			ans[i].pb(q.front().S);
			q.pop();
		}
	}
	return (q.empty() && mIdx > m);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> d >> m;
	FOR(i,1,m) cin >> a[i].F;
	FOR(i,1,m)a[i].S = i;
	sort(a+1,a+m+1);
	int lo = 1,hi = m,mid;
	while(lo < hi) {
		mid = lo+hi >> 1;
		if(valid(mid)) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	}
	assert(lo == hi);
	int machines = lo;
	valid(machines);
	cout << machines << "\n";
	FOR(i,1,n) {
		for(auto j:ans[i]) cout << j << " ";
		cout << "0\n";
	}
}
