/*
SOLUTION: Easier version of JAN 2017 Gold p2
exact same soln for both, only value of k = 1 here
*/
#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x,a) memset((x),(a),sizeof(x)) 
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

const int MAXN = 1e5+5;
const int MAXK = 25;
int dp[MAXN][MAXK][3];

inline bool canbeat(int a,int b) {
	if(a == 0 && b == 2)return true;
	if(a == 1 && b == 0)return true;
	if(a == 2 && b == 1)return true;
	return false;
}

int main() {
	ifstream fin("hps.in");
	ofstream fout("hps.out");
	#define cin fin
	#define cout fout
	int n; cin >> n; 
	char cha[n]; F0R(i,n) cin >> cha[i];
	int a[n]; 
	F0R(i,n) {
		if(cha[i] == 'H') a[i] = 0;
		else if(cha[i] == 'P') a[i] = 1;
		else a[i] = 2;
	}
	dp[0][0][0] = canbeat(0,a[0]);
	dp[0][0][1] = canbeat(1,a[0]);
	dp[0][0][2] = canbeat(2,a[0]);
	FOR(i,1,n-1) {
		F0R(j,2) {
			F0R(move,3) {
				dp[i][j][move] = canbeat(move,a[i]);
				int xtra = 0;
				if(j > 0) {
					F0R(other,3) {
						if(other == move)continue;
						xtra = max(xtra,max(dp[i-1][j][move],dp[i-1][j-1][other]));
					}
				} else {
					xtra = dp[i-1][j][move];
				}
				dp[i][j][move] += xtra;
			}
		}
	}
	int ans = 0;
	F0R(i,2) F0R(j,3) ans = max(ans,dp[n-1][i][j]);
	cout << ans;
}	
