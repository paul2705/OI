#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5e2+5;
int a[MAXN][MAXN],b[MAXN][MAXN];
int T,n,m,t,r,ans;
int tr[MAXN*2];
priority_queue<int> q;
void add(int x,int val){
	for (;x<=m;x+=x&-x) tr[x]+=val;
}
int sum(int x){
	int ret=0;
	for (;x>0;x-=x&-x) ret+=tr[x];
	return ret;
}
void solve1(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]!=2) continue;
			for (int x=max(i-r,1);x<=min(n,i+r);x++){
				for (int y=max(j-r,1);y<=min(m,j+r);y++){
					if (abs(x-i)+abs(y-j)<=r) b[x][y]++;
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			if (a[i][j]==1) q.push(b[i][j]);
	}
	for (int i=1;i<=t&&!q.empty();i++){
		ans+=q.top(); q.pop();
	}
	printf("%d\n",ans);
}
void solve2(){
	for (int i=1;i<=m;i++){
		if (a[1][i]!=2) continue;
		add(max(1,i-r),1); add(min(m,i+r)+1,-1);
	}
	for (int i=1;i<=m;i++){
		if (a[1][i]==1) q.push(sum(i));
	}
	for (int i=1;i<=t&&!q.empty();i++){
		ans+=q.top(); q.pop();
	}
	printf("%d\n",ans);
}
void solve3(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]!=2) continue;
			b[i][j]++; b[i][j-1]++; b[i][j+1]++; b[i-1][j]++; b[i+1][j]++;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) 
			if (a[i][j]==1) q.push(b[i][j]);
	}
	for (int i=1;i<=t&&!q.empty();i++){
		ans+=q.top(); q.pop();
	}
	printf("%d\n",ans);
}
int main(){
	freopen("portals.in","r",stdin);
	freopen("portals.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		ans=0; while (!q.empty()) q.pop();
		for (int i=1;i<=n;i++){
			tr[i]=0;
			for (int j=1;j<=m;j++) b[i][j]=0;
		}
		scanf("%d%d%d%d",&n,&m,&t,&r);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				char c=getchar(); while (c!='*'&&c!='O'&&c!='X')c=getchar();
				if (c=='*') a[i][j]=1;
				if (c=='O') a[i][j]=2;
				if (c=='X') a[i][j]=3;
			}
		}
		if (n<=55) solve1();
		else if (n==1) solve2();
		else if (r==1) solve3();
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
