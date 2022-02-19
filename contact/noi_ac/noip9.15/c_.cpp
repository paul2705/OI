#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],c[MAXN],x[MAXN];
int n,m,q;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	a[m+1]=1e9;
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		for (int j=1;j<=m;j++){
			if (c[i]>=a[j]&&c[i]<a[j+1]){
				x[i]=j;
				break;
			}
		}
		if (x[i]==0){
			if (c[i]>=a[n]) x[i]=n;
		}
	}
	for (int i=1,op,l,r,y;i<=q;i++){
		scanf("%d",&op);
		if (op==1){
			scanf("%d%d%d",&l,&r,&y);
			for (int k=l;k<=r;k++){
				c[k]+=y;
				for (int j=1;j<=m;j++){
					if (c[k]>=a[j]&&c[k]<a[j+1]){
						x[k]=j;
						break;
					}
				}
				if (c[k]>=a[n]) x[k]=n;
			}
		}
		if (op==2){
			scanf("%d%d",&l,&y);
			c[l]+=y;
			for (int j=1;j<=m;j++){
				if (c[l]>=a[j]&&c[l]<a[j+1]){
					x[l]=j;
					break;
				}
			}
			if (x[l]>=a[n]) x[l]=n;
		}
		if (op==3){
			scanf("%d%d",&l,&r);
			int ret=0;
			for (int i=l;i<=r;i++) ret+=x[i];
			printf("%d\n",ret);
		}
	}
	return 0;
}
