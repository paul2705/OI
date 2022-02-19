#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
const int MAXS=1<<5;
int f[MAXN][MAXS],num[MAXN][MAXS];
int n,m,pos[MAXN];
int bin[10],lis[10];
int ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d%d",&pos[i],&a,&b);
		for (int j=0;j<=5;j++) lis[j]=0;
		for (int j=1;j<=a;j++){
			int x; scanf("%d",&x); x-=pos[i];
			if (x<0) x+=n;
			lis[x]=-1;
		}
		for (int j=1;j<=b;j++){
			int x; scanf("%d",&x); x-=pos[i];
			if (x<0) x+=n;
			lis[x]=1;
		}
		for (int s=0;s<(1<<5);s++){
			bool flag=0;
			for (int j=0;j<5;j++){
				if (s&(1<<j)){
					if (lis[j]==1) flag|=1;
				}
				else if (lis[j]==-1) flag|=1;
			}
			num[i][s]=flag;
		}
//		cout<<i<<" "<<num[i][0]<<endl;
	}
	bin[0]=1;
	for (int i=1;i<=5;i++) bin[i]=bin[i-1]*2;
	for (int st=0;st<(1<<4);st++){
//		cout<<st<<endl;
		for (int i=1;i<=m;i++){
			for (int s=0;s<(1<<5);s++) f[i][s]=0;
		}
		int tmp=0,dist=min(5,pos[1]);
		if (pos[1]<=4) tmp=(st&(bin[4]-1-bin[pos[1]-1]-1));
		for (int s=0;s<(1<<dist);s++){
			int s1=(tmp>>(dist-1))+(s<<(5-dist));
			f[1][s1]=num[1][s1];
		}
		for (int i=2;i<=m;i++){
//			cout<<i<<endl;
			int dis1=5;
			if (pos[i]+4>n) dis1=n-pos[i]+1;
			for (int s=0;s<(1<<dis1);s++){
//				cout<<i<<" "<<pos[i]<<endl;
				int nst=s;
				int dis=min(5,pos[i]-pos[i-1]);
				if (dis1<5) nst=(st&(bin[5-dis1]-1)<<dis1)+s;
//				cout<<"in"<<" "<<dis<<endl;
				for (int s1=0;s1<(1<<dis);s1++){
					int pre=(nst&(bin[5-dis]-1)<<dis)+s1;
					f[i][nst]=max(f[i][nst],f[i-1][pre]+num[i][nst]);
				}
				if (i==m) ans=max(ans,f[m][nst]);
			}
		}
//		cout<<st<<endl;
	}
	printf("%d\n",ans);
	return 0;
}
