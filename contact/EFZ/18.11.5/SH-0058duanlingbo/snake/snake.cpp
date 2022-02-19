#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXQ=MAXN*MAXN+5;
bool use[MAXN][MAXN];
int n,m,t,q,sx,sy,pos,head=0,tail=0;
struct rec{
	int x,y;
} a[MAXQ];
bool f=1;
int main(){
	freopen("snake.in","r",stdin);
	freopen("snake.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&t,&q);
	for (int i=1,x,y;i<=t;i++) scanf("%d%d",&x,&y),use[x][y]=1;
	scanf("%d%d",&sx,&sy);
	use[sx][sy]=1; a[head++]=(rec){sx,sy};
	for (int i=1,op;i<=q;i++){
		scanf("%d",&op);
		if (op==1){
			char c=getchar(); while(c!='L'&&c!='R'&&c!='U'&&c!='D') c=getchar();
			if (c=='U') sx--;
			if (c=='D') sx++;
			if (c=='L') sy--;
			if (c=='R') sy++;
			if (use[sx][sy]) 
				if (f) f=0,pos=i;
            a[head++]=(rec){sx,sy};
			use[sx][sy]=1;
		}
		else {
			rec u=a[tail++];
			use[u.x][u.y]=0;
		}
	}
	if (f) printf("-1\n");
	else printf("%d\n",pos);
	fclose(stdin); fclose(stdout);
	return 0;
}
