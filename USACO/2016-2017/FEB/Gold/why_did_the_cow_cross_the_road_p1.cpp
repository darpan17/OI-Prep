#include <bits/stdc++.h>

#define F0R(i,n) for(auto i = 0; i < (n); i++)
#define FOR(i,a,b) for(auto i = (a); i <= (b); i++)
#define ROF(i,a,b) for(auto i = (a); i >= (b); i--)
#define ll long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define pii pair<int,int>

using namespace std;

const int MAXN = 105;
const int dx[] = {0,0,0,0,1,-1,3,-3,-1,-1,1,1,2,2,-2,-2};
const int dy[] = {1,3,-1,-3,0,0,0,0,-2,2,-2,2,1,-1,-1,1};
int n; ll t;
ll a[MAXN][MAXN];
ll dp[MAXN][MAXN];

inline bool v(int x,int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

struct Node {
	int x,y,steps;
	ll val;
	Node(int _x,int _y,ll _val,int _steps) {
		x = _x; y = _y; val = _val; steps = _steps;
	}
	const bool operator <(const Node& other) const {
		return val > other.val;
	}
};

int main() {
	freopen("visitfj.in","r",stdin);
	freopen("visitfj.out","w",stdout);

	scanf("%d%lld",&n,&t);
	F0R(i,n) F0R(j,n) scanf("%lld",&a[i][j]);
	F0R(i,n) F0R(j,n) dp[i][j] = 1e9;
	
	dp[0][0] = 0;

	priority_queue<Node> q;
	q.push(Node(0,0,0,0));

	ll result = 1e9;

	while(!q.empty()) {
		Node node = q.top(); q.pop();
		F0R(i,16) {
			int x = node.x + dx[i];
			int y = node.y + dy[i];
			int steps = node.steps + 1;
			if(!v(x,y)) continue;
			
			int dist = abs(n - 1 - node.x) + abs(n - 1 - node.y);
    		if (dist <= 2) {
      			result = min(result, node.val + dist * t);
    		}

			if(dp[x][y] > node.val+3*t+a[x][y]) {
				dp[x][y] = node.val+3*t+a[x][y];
				q.push(Node(x,y,dp[x][y],steps));
			} 
			
		}
	}
	printf("%lld",min(dp[n-1][n-1],result));
}
