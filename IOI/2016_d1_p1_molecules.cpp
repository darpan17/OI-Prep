#include "bits/stdc++.h"
#include "molecules.h"

#define F0R(i,n) for(auto i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define ROF(i,a,b) for(auto i = (a); i >= (b); i--)
#define pb push_back
#define vi vector<int> 
#define pii pair<int,int>
#define F first
#define S second
#define ll long long

using namespace std;

vi find_subset(int l,int u,vi w) {
	vector<pii> a;
	int n = w.size();
	F0R(i,n) {
		a.pb(make_pair(w[i],i));
	}
	sort(a.rbegin(),a.rend());
	int li = 0; ll sum = 0;
	F0R(i,n) {
		sum += a[i].F;
		if(sum >= l && sum <= u) {
			vi ans;
			FOR(j,li,i) ans.pb(a[j].S);
			sort(ans.begin(),ans.end());
			return ans;
		}
		while(sum > u && li <= i) {
			sum -= a[li++].F;
		}
	}	
	return vi{};
}
