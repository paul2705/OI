#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,m;
ll f[15][15][(1<<15)];
ll dp(int x,int y,ll b){
        if (f[x][y][b]>=0) return f[x][y][b];
        if (x==m) return (b==0);
        int xx,yy;
        if (y==n-1) xx=x+1,yy=0;
	        else xx=x,yy=y+1;
        ll mask=(1<<y); 
        if (b&mask) return f[x][y][b]=dp(xx,yy,b^mask);
        ll ans=dp(xx,yy,b^mask);
        if ((y+1<n) && !(b&(mask<<1))) ans+=dp(xx,yy,b^(mask<<1));
        return f[x][y][b]=ans;
}   
int main(){ 
        scanf("%d%d",&n,&m); 
        while (n>0&&m>0){
		for (int i=0;i<=m;i++)
			for (int j=0;j<=n;j++)
				for (int s=0;s<(1<<(max(n,m)+1));s++) f[i][j][s]=-1;
                printf("%lld\n",dp(0,0,0));
                scanf("%d%d",&n,&m);
        }
        return 0;
}

