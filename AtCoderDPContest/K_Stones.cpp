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
bool dp[MAXN];

int main() {
	int n,k; cin >> n >> k;
	int a[n]; F0R(i,n) cin >> a[i];
	F0R(i,k+1) {
		F0R(j,n) {
			if(i>=a[j]) if(!dp[i-a[j]]) dp[i] = true;
		}
	}
	cout << (dp[k]?"First":"Second");
}	
