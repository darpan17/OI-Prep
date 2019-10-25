#include <bits/stdc++.h>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORE(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

int dp[3005][3005];

int main(){
	string s,t; cin >> s >> t;
	int n = s.size(), m = t.size();
	FORE(i,1,n){
		FORE(j,1,m){
			if(s[i-1] == t[j-1]){
				dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+1));
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string ans = "";
	int i = n, j = m;
	while(true){
		if(i == 0 || j == 0)break;
		if(dp[i][j] > dp[i-1][j] && dp[i][j] > dp[i][j-1] && dp[i][j] == dp[i-1][j-1]+1){
			ans += s[i-1];
			i--; j--;
		}else if(dp[i][j] > dp[i-1][j] && dp[i][j] == dp[i][j-1]){
			j--;
		}else{
			i--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout << ans;
	return 0;
}
