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
#include <stack>
#include <map>
 
#define FOR(i,n) for(auto i = 0; i != n; i++)
#define FORE(i,a,b) for(auto i = a; i <= b; i++)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
 
const int INF = 1<<28;
const ll LINF = 1LL<<59LL;
const ll MOD = 1000000007;
const int MAXN = 100005;
 
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	int n; cin >> n;
	int player;
	ll diff = 0;
	int p1 = 0, p2 = 0;
	ll x,y;
	FOR(i,n){
		cin >> x >> y;
		p1 += x; p2 += y;
		if(p1-p2 > diff){
			player = 1;
			diff = p1-p2;
		}else if(p2-p1 > diff){
			player = 2;
			diff = p2-p1;
		}
	}
	cout << player << " " << diff;
	return 0;
}
