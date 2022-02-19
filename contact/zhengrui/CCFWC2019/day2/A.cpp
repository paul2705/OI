#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e2+5;
const int MAXP=MAXN*3;
int n,a[MAXN],b[MAXN],d[MAXN];
int w[MAXP],f[MAXP][MAXP];
int tmp[MAXN],cnt,sz=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&d[i]);
	for (int i=1;i<=n;i++) tmp[cnt++]=a[i],tmp[cnt++]=b[i];
	sort(tmp,tmp+cnt);
	int nn=unique(tmp,tmp+cnt)-tmp-1;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(tmp,tmp+nn,a[i])-tmp;
		b[i]=lower_bound(tmp,tmp+nn,b[i])-tmp;
		a[i]++; b[i]++;
//		cout<<a[i]<<" "<<b[i]<<endl;
		sz=max(sz,a[i]); sz=max(sz,b[i]);
	}
	for (int i=1;i<=sz;i++) f[i][i]=0;
	for (int len=1;len<=sz;len++){
		for (int i=1;i<=sz;i++){
			int j=i+len; if (j>sz) break;
			int dis=0,pos=0;
			for (int k=1;k<=n;k++){
				if (a[k]>=i&&b[k]<=j){
					if (d[k]>=dis) dis=d[k],pos=k;
				}
			}
			if (pos!=0){
				f[i][j]=1e9;
				for (int k=a[pos];k<=b[pos];k++){
					f[i][j]=min(f[i][j],f[i][k-1]+f[k+1][j]+dis);
				}
			}
		}
	}
	printf("%d\n",f[1][sz]);
	return 0;
}
