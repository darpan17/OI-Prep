#include <bits/stdc++.h>

#define F0R(i,n) for(auto i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define ROF(i,a,b) for(auto i = (a); i >= (b); i--)
#define ll long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>

using namespace std;

const int MAXN = 5e4+5;
int n,k;
ll a[MAXN],dp[MAXN];
ll sparse[MAXN][30];

void build() {
	F0R(i,n)sparse[i][0] = a[i];
	FOR(sz,1,25) {
		for(int i = 0; i+(1<<sz)-1 < n; i++) {
			sparse[i][sz] = max(sparse[i][sz-1],sparse[i+(1<<sz-1)][sz-1]);
		}
	}
}
ll get(int l,int r) {
	int sz = log2(r-l+1);
	return max(sparse[l][sz],sparse[r-(1<<sz)+1][sz]);
}

int main() {
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);

	scanf("%d%d",&n,&k);
	F0R(i,n)scanf("%lld",&a[i]);
	build();
	dp[0] = a[0];
	FOR(i,1,n-1) {
		ROF(j,i,max(0,i-k+1)) {
			dp[i] = max(dp[i],dp[j-1]+(i-j+1)*get(j,i));
		}
	}
	printf("%lld\n",dp[n-1]);
}
