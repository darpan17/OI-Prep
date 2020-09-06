#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	int n; scanf("%d",&n);
	double a[n]; 
	for(int i=0;i<n;i++) {
		ll x; scanf("%lld",&x);
		a[i] = x;
	}
	sort(a, a+n);
	
	// double left[n], right[n];
	double maxLeft[n], maxRight[n];
	
	// left[0] = 0;
	// for(int i=1;i<n;i++) {
		// left[i] = max(left[i-1]+1, 
	// }
	
	maxLeft[0] = 0;
	for(int i=1;i<n;i++) {
		maxLeft[i] = max(maxLeft[i-1]+1, a[i]-a[i-1]);
	}
	maxRight[n-1] = 0;
	for(int i=n-2;i>=0;i--) {
		maxRight[i] = max(maxRight[i+1]+1, a[i+1]-a[i]);
	}
	
	double ans = 1e18;
	for(int i=1;i<n;i++) {
		double dist = (a[i]-a[i-1])/2.0;
		// if(maxRight[i]+2+maxLeft[i-1] >= dist) {
			// ans = min(ans, max((maxLeft[i-1]+1, maxRight[i]+1)));
		// } else {
			// ans = min(ans, dist);
		// }
		ans = min(ans, max({maxLeft[i-1]+1, maxRight[i]+1, dist}));
		// cout << "maxLeft[i-1] = " << maxLeft[i-1] << " maxRight[i] = " << maxRight[i] << " dist = " << dist << endl;
		// cout << "i = " << i << " ans = " << ans << endl;
	}
	for(int i=0;i<n;i++) ans = min(ans, max(maxLeft[i], maxRight[i]));
	
	printf("%0.1f", ans);
}
