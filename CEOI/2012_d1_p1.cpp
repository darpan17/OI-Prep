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
     
    signed main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
    	int n,d,m; cin >> n >> d >> m;
    	pii a[m+5]; FOR(i,1,m) cin >> a[i].F;
    	FOR(i,1,m)a[i].S = i;
    	sort(a+1,a+m+1);
    	int dayNumber = 1, jobNumber = 1, machines = 1;
    	while(jobNumber < m) {
    		if(dayNumber-a[jobNumber].F > d) {
    			machines++;
    			jobNumber = machines*(dayNumber-1)+1;
    		} 
    		if(jobNumber/machines == dayNumber && jobNumber % machines == 0)++dayNumber;
    		jobNumber++;
    	}
    	cout << machines << "\n";
    	jobNumber = 1;
    	F0R(i,n) {
    		F0R(j,machines) {
    			if(jobNumber > m) {
    				cout << "0\n";
    				goto nextDay;
    			} else {
    				cout << a[jobNumber++].S << " ";
    			}
    		}
    	
    		cout << "0\n";
    		nextDay:;
    	}
    }
