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
	int a,b,c; cin >> a >> b >> c;
	map<int,int> m;
	int x;
	FOR(i,a+b+c){
		cin >> x;
		m[x]++;
	}
	vector<int> ans;
	for(auto& i:m){	
		if(i.ss >= 2){
			ans.pb(i.ff);
		}
	}	
	cout << ans.size() << "\n";
	for(auto& i:ans)cout << i << "\n";
	return 0;
}
