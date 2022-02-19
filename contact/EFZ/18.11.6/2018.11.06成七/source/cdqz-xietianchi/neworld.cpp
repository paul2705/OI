#include <bits/stdc++.h>


using namespace std;
const int N = 500 + 10;
typedef long long ll;

const int dx[] = {0 , 0 , 1 , -1};
const int dy[] = {1 , -1 , 0 , 0};

struct E {
	int to , nex , val;
} e[N * N * 4];
int head[N * N] , ecnt;

void addE(int fr,int to,int val) {
	e[++ecnt] = (E) {
		to,head[fr],val
	};
	head[fr] = ecnt;
}
int mat[N][N] , n , m;

int id(int x,int y) {
	return (x - 1) * m + y;
}

struct Node {
	int pos ;
	ll val;
	inline bool operator < (const Node &a) const {
		return val > a.val;
	}
};

priority_queue<Node> qu;
ll dis[N * N];
void dj(int s) {
	memset(dis , 0x3f , sizeof dis);
	dis[s] = 0ll;
	qu.push((Node) {s,0});

	while (qu.size()) {
		Node cur = qu.top();
		qu.pop();
		if (dis[cur.pos] < cur.val) continue;
		for (int j = head[cur.pos]; j; j=e[j].nex)
		if (dis[e[j].to] > dis[cur.pos] + e[j].val) {
			dis[e[j].to] = dis[cur.pos] + e[j].val;
			qu.push((Node) {e[j].to , dis[e[j].to]});
		}
	}
}

int r , c , l , p , q;
int main() {
	freopen("neworld.in","r",stdin);
	freopen("neworld.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	scanf("%d",&mat[i][j]);

	scanf("%d%d%d%d%d",&r,&c,&l,&p,&q);

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k] , ny = j + dy[k];
		if (nx > n || nx < 0 || ny > m || ny < 0 ) continue;
			addE(id(nx , ny) , id(i , j) , mat[i][j]);
		}
	}

	dj(id(r,c));
	printf("%lld\n" , max(0ll , l - dis[id(p,q)]) );

	return 0;
}
