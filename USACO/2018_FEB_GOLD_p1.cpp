#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)
#define ll long long

using namespace std;

ll a[100005];

inline bool solve(int n,ll dep,ll step){
	bool mark[n]; FOR(i,n) mark[i] = false;
	mark[0] = true;
	int last = 0;
	FORE(i,1,n-1){
		if(a[i] <= dep){
			if(i-last <= step){
				last = i;
			}else{
				return false;
			}
		}
		if(i-last > step){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n,k; scanf("%d%d",&n,&k);
	FOR(i,n) scanf("%lld",&a[i]);         
	ll x,y;
	FOR(i,k){
		scanf("%lld%lld",&x,&y);
		printf("%d\n",solve(n,x,y));
	}
	return 0;
}
