/* Soln: dp with some observations */

#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <cassert>
#include <map>

#define FOR(i,n) for(auto i = 0; i != n; i++)
#define FORE(i,a,b) for(auto i = a; i <= b; i++)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define LB lower_bound
#define UB upper_bound
#define ff first
#define ss second

const int INF = 1<<28;
const ll LINF = 1LL<<59LL;
const ll MOD = 1000000007;
const int MAXN = 1000000007;

using namespace std;

int main(){
	ifstream fin;
	ofstream fout;
	fin.open("buckets.in");
	fout.open("buckets.out");
	#define cin fin
	#define cout fout
	char grid[11][11]; int dp[11][11];
	FOR(i,11)FOR(j,11) dp[i][j] = INF;
	pair<int,int> l,b;
	FORE(i,1,10){
		FORE(j,1,10){
			cin >> grid[i][j];
			if(grid[i][j] == 'L') l = {i,j};
			else if(grid[i][j] == 'B') b = {i,j};
		}
	}
	dp[l.ff][l.ss] = 0;
	// + -> ulrd
	for(int i = l.ff-1; i >= 1; i--){
		if(grid[i][l.ss] == 'R')dp[i][l.ss] = INF;
		else if(dp[i+1][l.ss] == INF)dp[i][l.ss] = INF;
		else dp[i][l.ss] = dp[i+1][l.ss]+1;
	}
	for(int i = l.ss-1; i >= 1; i--){
		if(grid[l.ff][i] == 'R')dp[l.ff][i] = INF;
		else if(dp[l.ff][i+1] == INF)dp[l.ff][i] = INF;
		else dp[l.ff][i] = dp[l.ff][i+1]+1;
	}
	FORE(i,l.ss+1,10){
		if(grid[l.ff][i] == 'R')dp[l.ff][i] = INF;
		else if(dp[l.ff][i-1] == INF)dp[l.ff][i] = INF;
		else dp[l.ff][i] = dp[l.ff][i-1]+1;
	}
	FORE(i,l.ff+1,10){
		if(grid[i][l.ss] == 'R')dp[i][l.ss] = INF;
		else if(dp[i-1][l.ss] == INF)dp[i][l.ss] = INF;
		else dp[i][l.ss] = dp[i-1][l.ss]+1;
	}
	// top-left
	for(int i = l.ff; i > 0; i--){
		for(int j = l.ss; j > 0; j--){
			if(grid[i][j] != 'R')dp[i][j] = min(dp[i][j],min(dp[i+1][j],dp[i][j+1])+1);
			else dp[i][j] = INF;
		}
	}
	// top-right
	for(int i = l.ff; i > 0; i--){
		FORE(j,l.ss,10){
			if(grid[i][j] != 'R')dp[i][j] = min(dp[i][j],min(dp[i+1][j],dp[i][j-1])+1);
			else dp[i][j] = INF;
		}
	}
	// bottom-left
	FORE(i,l.ff,10){
		for(int j = l.ss; j > 0; j--){
			if(grid[i][j] != 'R')dp[i][j] = min(dp[i][j],min(dp[i-1][j],dp[i][j+1])+1);
			else dp[i][j] = INF;
		}
	}
	// bottom-right
	FORE(i,l.ff,10){
		FORE(j,l.ss,10){
			if(grid[i][j] != 'R')dp[i][j] = min(dp[i][j],min(dp[i-1][j],dp[i][j-1])+1);
			else dp[i][j] = INF;
		}
	}
	cout << dp[b.ff][b.ss]-1;
	return 0;
}
