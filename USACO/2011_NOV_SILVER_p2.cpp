/* Soln: manipulating the deque properly so as to get the min no. of x coordinates.*/

#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <cassert>
#include <map>

#define FOR(i,n) for(auto i = 0; i != n; i++)
#define FORE(i,a,b) for(auto i = a; i <= b; i++)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define LB lower_bound
#define UB upper_bound
#define ff first
#define ss second
#define pll pair<ll,ll>

const int INF = 1<<28;
const ll LINF = 1LL<<59LL;
const ll MOD = 1000000007;
const int MAXN = 200005;

using namespace std;

bool comp(pll& a, pll& b){
	return a.ff < b.ff;
}

int main(){
	int n; scanf("%d",&n);
	set<ll> s;
	vector<pll> a(n); FOR(i,n){cin >> a[i].ff >> a[i].ss; s.insert(a[i].ss);}
	sort(a.begin(),a.end(),comp);
	int uniq = s.size();
	map<ll,ll> m;
	deque<pll> q;
	ll ans = LINF, ctr = 0,diff;
	while(true){
		if(m.size() >= uniq){
			diff = q.back().ff-q.front().ff;
			ans = min(ans,diff);
			m[q.front().ss]--;
			if(m[q.front().ss] == 0){
				m.erase(q.front().ss);
			}
			q.pop_front();
		}else{
			if(ctr >= n)break;
			q.pb(a[ctr]); 
			m[a[ctr].ss]++;
			ctr++;
		}
	}
	printf("%lld",ans);
	return 0;
}
