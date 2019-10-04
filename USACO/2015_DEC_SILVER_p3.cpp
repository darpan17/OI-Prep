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
const int MAXN = 200005;
 
using namespace std;

int main(){
	freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);
	int n,q; scanf("%d%d'",&n,&q);
	int cow[n+1]; FORE(i,1,n)cin >> cow[i];
	int hol[n+1],gue[n+1],jer[n+1];
	FOR(i,n+1)hol[i] = gue[i] = jer[i] = 0;
	FORE(i,1,n){
		if(cow[i] == 1){hol[i] = hol[i-1]+1; gue[i] = gue[i-1]; jer[i] = jer[i-1];}
		else if(cow[i] == 2){gue[i] = gue[i-1]+1; hol[i] = hol[i-1]; jer[i] = jer[i-1];}
		else {jer[i] = jer[i-1]+1; hol[i] = hol[i-1]; gue[i] = gue[i-1];}
	}
	int x,y;
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%d ",hol[y]-hol[x-1]);
		printf("%d ",gue[y]-gue[x-1]);
		printf("%d\n",jer[y]-jer[x-1]);
	}
	return 0;
}
