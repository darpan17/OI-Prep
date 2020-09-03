#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define F first
#define S second

const int MAXN = 50005;
int n;
pair<ll,ll> a[MAXN];
ll minSparse[MAXN][20], maxSparse[MAXN][20];

void build(bool x) {
	if(x) {
		for(int i=0;i<n;i++) {
			minSparse[i][0] = a[i].S;
			maxSparse[i][0] = a[i].S;
		}
	} else {
		for(int i=0;i<n;i++) {
			minSparse[i][0] = a[i].F;
			maxSparse[i][0] = a[i].F;	
		}
	}
	for(int sz=1; (1<<sz)<=n; sz++) {
		for(int i=0; (i+(1<<sz)-1)<n; i++) {
			minSparse[i][sz] = min(minSparse[i][sz-1], minSparse[i+(1<<sz-1)][sz-1]);
			maxSparse[i][sz] = max(maxSparse[i][sz-1], maxSparse[i+(1<<sz-1)][sz-1]);
		}
	}
}

ll getMin(int l, int r) {
	int sz = log2(r-l+1);
	return min(minSparse[l][sz], minSparse[r-(1<<sz)+1][sz]);
}
ll getMax(int l, int r) {
	int sz = log2(r-l+1);
	return max(maxSparse[l][sz], maxSparse[r-(1<<sz)+1][sz]);
}

int main() {
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld%lld",&a[i].F,&a[i].S);
	sort(a, a+n);
	build(true);
	ll ans = 0;
	ll oriArea = (getMax(0,n-1)-getMin(0,n-1)) * (a[n-1].F-a[0].F);
	for(int i=0;i<n-1;i++) {
		ll curArea = (getMax(0,i)-getMin(0,i)) * (a[i].F-a[0].F) + (getMax(i+1,n-1)-getMin(i+1,n-1)) * (a[n-1].F-a[i+1].F);
		// printf("curarea = %lld oriArea = %lld\n",curArea,oriArea);
		ans = max(ans, oriArea-curArea);
	}

	sort(a, a+n, [&](pair<ll,ll> lhs, pair<ll,ll> rhs) {
		return (lhs.S < rhs.S) || (lhs.S == rhs.S && lhs.F < rhs.F);
	});

	build(false);
	for(int i=0;i<n-1;i++) {
		ll curArea = (getMax(0,i)-getMin(0,i)) * (a[i].S-a[0].S) + (getMax(i+1,n-1)-getMin(i+1,n-1)) * (a[n-1].S-a[i+1].S);
		// printf("curarea = %lld oriArea = %lld\n",curArea,oriArea);
		ans = max(ans, oriArea-curArea);
	}
	printf("%lld",ans);
}
