#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e4+4;
int n,m,c,v,w,d;
ll f[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&v,&w,&d);
		if (d*v>c)
			for (int j=v;j<=c;j++)
				f[j]=max(f[j],f[j-v]+w);
		else{
			for (int k=1;k<=d;k*=2){
				if (c<v*k) break;
				for (int j=c;j>=v*k;j--)
					f[j]=max(f[j],f[j-v*k]+w*k);
				d-=k;
			}
			if (d>0)
				for (int j=c;j>=v*d;j--)
					f[j]=max(f[j],f[j-v*d]+w*d);
		}
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&v,&w,&d);
		for (int j=c;j>=0;j--)
			for (int k=0;k<=j;k++)
				f[j]=max(f[j],f[j-k]+(v*k+w)*k+d);
	}
	printf("%lld\n",f[c]);
	return 0;
}
