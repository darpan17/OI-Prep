/*
Soln seen.
In this problem, we have two separate approaches, one that'll solve subtask 1-4 and another for subtask 5.
The O(n^3) solution for subtasks 1-4 is that,
For each bit, we see whether it is possible that the bit is not set in the final answer.
So we calculate dp[number of elements][number of partitions] and dp[i][j] is true iff it is possible to set the current bit to 0 if
there is a partition at index k.
For the O(n^2) solution, our states are a bit different
We calculate dp[number of elements] and dp[i] stores the min number of partitions required if we want to set the current bit to 0.
Since we try to minimize the optimal answer, greedily minimizing the highest bit each time works.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>

#define ll long long int
#define F0R(i,n) for(auto i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define ROF(i,a,b) for(auto i = (a); i >= (b); i--)
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vv vector
#define F first
#define S second
#define pb push_back
#define vi vector<int>

using namespace std;

const int MAXN = 2005;
int n,a,b;
ll pre[MAXN];

inline bool possible(ll num,ll currentSum,int bit) {
	return ((((currentSum|num)-currentSum)) < (1LL<<bit));
}

// O(n^2) solution
bool dpN2(ll sum,int bit) {
	int dp[n+5];
	memset(dp,0,sizeof(dp));
	FOR(i,1,n) {
		dp[i] = 100000;
		ROF(j,i-1,0) {
			if(possible(pre[i]-pre[j],sum,bit)) {
				dp[i] = min(dp[i],dp[j]+1);
			}
		}
	}
	return (dp[n] <= b);
}

// O(n^3) solution
bool dpN3(ll sum,int bit) {
	bool dp[n+5][n+5];
	memset(dp,false,sizeof(dp));
	dp[0][0] = true;
	FOR(i,1,n) {
		ROF(j,i-1,0) {
			// j elements done already
			if(possible(pre[i]-pre[j],sum,bit)) {
				FOR(k,1,n) {
					if(dp[j][k-1]) dp[i][k] = true;
				}
			}
		}
	}
	bool res = false;
	FOR(i,a,b) res |= dp[n][i];
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> a >> b;
	ll arr[n+5]; FOR(i,1,n) cin >> arr[i];
	FOR(i,1,n) pre[i] = pre[i-1]+arr[i];
	ll ans = 0;
	ROF(i,45,0) {
		if(a == 1) {
			if(!dpN2(ans,i)) ans += (1LL<<i);
		} else {
			if(!dpN3(ans,i)) ans += (1LL<<i);
		}
	}
	cout << ans;
}
