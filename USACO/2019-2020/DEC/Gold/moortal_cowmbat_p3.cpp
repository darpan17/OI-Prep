#include <bits/stdc++.h>
using namespace std;

#define F0R(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define F first
#define S second

const int MAXN = 1e5+5;
int n,m,k;
string s;
int cost[30][30];
int dp[MAXN][30],pre[MAXN][30],mindp[MAXN];

int main() {
	freopen("cowmbat.in","r",stdin);
	freopen("cowmbat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	char ts[n]; scanf("%s",ts); s = (string)ts;
	F0R(i,m) F0R(j,m) scanf("%d",&cost[i][j]);
	F0R(i,m) F0R(j,m) F0R(kk,m) cost[j][kk] = min(cost[j][kk],cost[j][i]+cost[i][kk]);

	F0R(i,m) pre[0][i] = cost[s[0]-'a'][i];
	FOR(i,1,n-1) {
		F0R(j,m) {
			pre[i][j] = pre[i-1][j]+cost[s[i]-'a'][j];
		}
	}
	
	F0R(i,n) F0R(j,m) dp[i][j] = 1e8;
	
	FOR(i,1,n-1) {
		F0R(j,m) {
			if(i >= k-1) {
				dp[i][j] = min(dp[i][j],dp[i-1][j]+cost[s[i]-'a'][j]);
				if(i >= k) {
					F0R(kk,m) {
						dp[i][j] = min(dp[i][j],dp[i-k][kk]+pre[i][j]-pre[i-k][j]);
					}
				} else {
					F0R(kk,m) {
						dp[i][j] = pre[i][j];
					}
				}
			}
		
		}
	}
	int ans = 1e8;
	F0R(i,m) ans = min(ans,dp[n-1][i]);
	printf("%d",ans);
}
