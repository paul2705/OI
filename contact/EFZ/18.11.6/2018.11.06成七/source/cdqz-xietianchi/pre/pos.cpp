#include <bits/stdc++.h>
#define fir first
#define sec second
#define mp make_pair
#define inf 1000000
using namespace std;
typedef pair<int,int> pii;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

const int N = 50;

char s[N][N];
pii wxh[N*N] , d[N * N];int dcnt;
int T , n , m , k;
int dead[N][N] , dis[N][N];
int near[N][N][N] , vis[N][N];

queue <pii> q;

int main(){
	freopen("pos.in","r",stdin);
	freopen("pos.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		dcnt = 0;
		scanf("%d%d%d",&n,&m,&k);
		for (int i = 1;i <= n;i++){
			scanf("%s",s[i]+1);
			for (int j = 1;j <= m;j++){
				if (s[i][j] == 'd'){
					d[++dcnt] = mp(i,j);
				}
			}
		}
		for (int i = 1;i <= k;i++) scanf("%d%d",&wxh[i].first,&wxh[i].second);
		
		if (!k){
			puts("0");
			continue;
		}else{
			memset(dead , 0x3f , sizeof dead);
			for (int i = 1;i <= k;i++){
				int x = wxh[i].first , y = wxh[i].second;
				dead[x][y] = 0;
				if (s[x][y] == 'W') continue;
				q.push(make_pair(x,y));
			}
			
				
			while (q.size()){
				pii cur = q.front();q.pop();
				vis[cur.fir][cur.sec] = true;
				for (int i = 0;i < 4;i++){
					int nx = cur.fir + dx[i] , ny = cur.sec + dy[i];
					if (nx < 0 || nx > n || ny < 0 || ny < m) continue;
					if (dead[nx][ny] > dead[cur.fir][cur.sec] + 1){
						dead[nx][ny] = min(dead[nx][ny] , dead[cur.fir][cur.sec] + 1);
						q.push(mp(nx,ny));
					}
				}
			}
			
			
			for (int i = 1;i <= dcnt;i++)
			{
				for (int j = 1;j <= n;j++)
				for (int k = 1;k <= m;k++)
				near[j][k][i] = inf;
				memset(vis , 0 , sizeof vis);
				
				near[d[i].fir][d[i].sec][i] = 0;
				vis [d[i].fir][d[i].sec] = 1;
				q.push(mp(d[i].fir , d[i].sec));
					
				while (q.size()){
					pii cur = q.front();q.pop();
					vis[cur.fir][cur.sec] = true;
					for (int j = 0;j < 4;j++){
						int nx = cur.fir + dx[j] , ny = cur.sec + dy[j];
						if (nx < 0 || nx > n || ny < 0 || ny < m) continue;
						if (vis[nx][ny]) continue;
						
						
						if (dead[nx][ny] > near[cur.fir][cur.sec][i] + 1){
							near[nx][ny][i] = min( near[nx][ny][i] , near[cur.fir][cur.sec][i] + 1);
							q.push(mp(nx,ny));
						}
					}		
				}
				
			}
			
			int maxn = 0;
			for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++){
				if (s[i][j] != 'P') continue;
				int minm = 1000000;	
				for (int l = 1;l <= dcnt;l++){
					minm = min(minm , near[i][j][l]);
				}
				if (minm >= 1000) {
					puts("Death");
					goto Wxh;
				}
				maxn = max(minm , maxn);
			
			}
			
			printf("%d\n",maxn);
		}
		
		Wxh:;
 	}
	return 0;
}
