#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=5e2+5;
const int MAXM=5e2+5;
const int MAXT=MAXN*MAXM;
const int inf=1e9;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int f[15][15][MAXN][MAXM];
struct rec{
    int x,y;
} to[MAXN][MAXM][5];
int n,w,h;
char a[MAXN][MAXM];
struct que{
    int x,y,dis;
};
vector<que> lis;
queue<que> q1,q2;
int res;
bool use[MAXN][MAXM];
bool bk[MAXN][MAXM][5];
bool cmp(que a,que b){ return a.dis<b.dis; }
rec dfs(int x,int y,int dir){
	if (bk[x][y][dir]) return to[x][y][dir]=(rec){w+1,0};
	if (to[x][y][dir].x!=0) return to[x][y][dir];
	bk[x][y][dir]=1;
	int nx=x+dx[dir],ny=y+dy[dir];
	if (a[nx][ny]=='A') to[x][y][dir]=dfs(nx,ny,(dir+3)%4);
	else if (a[nx][ny]=='C') to[x][y][dir]=dfs(nx,ny,(dir+1)%4);
    else if (a[nx][ny]=='x') to[x][y][dir]=(rec){x,y};
	else to[x][y][dir]=dfs(nx,ny,dir);
	bk[x][y][dir]=0;
	return to[x][y][dir];
}
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	scanf("%d%d%d",&n,&h,&w);
	for (int i=0;i<=h+1;i++) a[0][i]=a[w+1][i]='x';
	for (int i=0;i<=h+1;i++) a[i][0]=a[i][h+1]='x';
	for (int i=1;i<=w;i++){
        for (int j=1;j<=h;j++){
            char c=getchar();
            while ((c<'1'||c>'9')&&(c!='x')&&c!='A'&&c!='C'&&c!='.') c=getchar();
            a[i][j]=c;
        }
    }
    for (int i=1;i<=w;i++)
        for (int j=1;j<=h;j++)
            for (int k=0;k<4;k++){
                to[i][j][k]=dfs(i,j,k);
            }
  //  cout<<res<<endl;
    for (int l=1;l<=n;l++){
        for (int r=1;r<=n;r++){
            for (int i=1;i<=w;i++){
                for (int j=1;j<=h;j++){
                    if (l!=r) f[l][r][i][j]=inf;
                    else if (a[i][j]-'0'!=l) f[l][r][i][j]=inf;
                    else f[l][r][i][j]=0;
                }
            }
        }
    }
    for (int len=0;len<=n;len++){
        for (int l=1;l<=n;l++){
            int r=l+len;
            if (r>n) break;
            lis.clear();
            while (!q1.empty()) q1.pop();
            while (!q2.empty()) q2.pop();
            for (int i=1;i<=w;i++){
                for (int j=1;j<=h;j++){
                    for (int k=l;k<r;k++){
                        f[l][r][i][j]=min(f[l][r][i][j],f[l][k][i][j]+f[k+1][r][i][j]);
                    }
					use[i][j]=0;
					if (f[l][r][i][j]==inf) continue;
                    lis.push_back((que){i,j,f[l][r][i][j]});
                    use[i][j]=1;
                }
            }
            sort(lis.begin(),lis.end(),cmp);
            for (int i=0;i<lis.size();i++){
                que u=lis[i];
                q1.push(u);
            }
            while (!q1.empty()||!q2.empty()){
                que u1;
                if (!q1.empty()) u1=q1.front();
                else u1.dis=inf+5;
                que u2;
                if (!q2.empty()) u2=q2.front();
                else u2.dis=inf+5;
                que u;
                if (u1.dis<u2.dis){
                    u=u1; q1.pop();
                }
                else {
                    u=u2; q2.pop();
                }
                for (int i=0;i<4;i++){
                    rec v=to[u.x][u.y][i];
                    use[u.x][u.y]=0;
                    if (f[l][r][v.x][v.y]>f[l][r][u.x][u.y]+1){
                        f[l][r][v.x][v.y]=f[l][r][u.x][u.y]+1;
                        if (!use[v.x][v.y]){
                            q2.push((que){v.x,v.y,f[l][r][v.x][v.y]});
                            use[v.x][v.y]=1;
                        }
                    }
                }
            }
        }
    }
    int ans=inf;
    for (int i=1;i<=w;i++){
        for (int j=1;j<=h;j++){
            ans=min(ans,f[1][n][i][j]);
        }
    }
    printf("%d\n",ans==inf?-1:ans);
    fclose(stdin); fclose(stdout);
    return 0;
}

