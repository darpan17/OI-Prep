#include <bits/stdc++.h>
using namespace std;
#define F0R(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)
#define ll long long
#define F first
#define S second
int main() {
	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);
	int n; scanf("%d",&n);
	int a[n]; F0R(i,n-1) scanf("%d",&a[i]);
	FOR(i,1,n) {
		vector<int> res; 
		res.push_back(i);
		F0R(j,n-1) {
			res.push_back(a[j]-res.back());
		}
		vector<int> ans = res;
		sort(res.begin(), res.end());
		bool ok = (res[0] > 0);
		FOR(i,1,n-1) {
			if(res[i] < 0 || res[i] == res[i-1]) {
				ok = false; break;
			}
		}
		if(ok) {
			printf("%d",ans[0]);
			FOR(j,1,n-1) printf(" %d",ans[j]);
			return 0;
		}
	}
}

