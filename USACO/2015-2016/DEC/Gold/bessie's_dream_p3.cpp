#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x,a) memset(x,a,sizeof(x))
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};

struct Tile {
	int r,c,dir;
	bool smell;
	Tile(): r(0),c(0),dir(0),smell(false){}
	Tile(int _r,int _c,int _dir,bool _smell): r(_r),c(_c),dir(_dir),smell(_smell){}
	
	void print() { 
		//~ cout << "r = " << r << " c = " << c << " dir = " << dir << " smell = " << smell << endl; 
	}
};

const int MX = 1005;
// dist[i][j][k][l] = min distance if Bessie is in cell (i,j) coming from cell(i+dr[k],j+dc[k]) and has smell l
int dist[MX][MX][6][2];
int grid[MX][MX];
int n,m;

inline bool valid(int r,int c) { 
	return r >= 0 && c >= 0 && r < n && c < m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ifstream fin("dream.in");
	ofstream fout("dream.out");
	#define cin fin
	#define cout fout
	cin >> n >> m;
	F0R(i,n) F0R(j,m) cin >> grid[i][j];
	MS(dist,-1);
	dist[0][0][5][0] = 0;
	queue<Tile> q;
	q.push(Tile(0,0,5,0));
	while(!q.empty()) {
		Tile t = q.front(); q.pop();
		//~ t.print();
		if(t.r == n-1 && t.c == m-1) {
			cout << dist[t.r][t.c][t.dir][t.smell];
			return 0;
		}
		if(valid(t.r+dr[t.dir],t.c+dc[t.dir]) && grid[t.r][t.c] == 4 && t.dir != 5) {
			// its already sliding in some direction
			if(grid[t.r+dr[t.dir]][t.c+dc[t.dir]] != 0 && grid[t.r+dr[t.dir]][t.c+dc[t.dir]] != 3) {
				if(dist[t.r+dr[t.dir]][t.c+dc[t.dir]][t.dir][0] == -1) {
					dist[t.r+dr[t.dir]][t.c+dc[t.dir]][t.dir][0] = dist[t.r][t.c][t.dir][t.smell]+1;
					q.push(Tile(t.r+dr[t.dir],t.c+dc[t.dir],t.dir,false));
					continue;
				}
			} 
		}
		F0R(i,4) {
			if(valid(t.r+dr[i],t.c+dc[i]) && grid[t.r+dr[i]][t.c+dc[i]] != 0) {
				if(grid[t.r+dr[i]][t.c+dc[i]] == 3 && !t.smell) continue;
				Tile nxt;
				nxt.r = t.r+dr[i]; nxt.c = t.c+dc[i];
				nxt.smell = t.smell;
				if(grid[t.r+dr[i]][t.c+dc[i]] == 2) nxt.smell = true;
				else if(grid[t.r+dr[i]][t.c+dc[i]] == 4) nxt.smell = false;
				nxt.dir = i;
				if(dist[nxt.r][nxt.c][i][nxt.smell] != -1) continue;
				dist[nxt.r][nxt.c][i][nxt.smell] = dist[t.r][t.c][t.dir][t.smell]+1;
				q.push(nxt);
			}
		}
	}
	cout << -1;
}	
