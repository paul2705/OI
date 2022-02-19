#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int k,p,a[25],ans[55],c[25][55];
void pre(){
	memset(c,0,sizeof(c));
	c[0][1]=1;
	int l=1;
	for (int i=1;i<=11;i++){
		for (int j=1;j<=l;j++) c[i][j]=c[i-1][j];
		for (int j=1;j<=l;j++) c[i][j]*=k;
		for (int j=1;j<=l;j++){
			c[i][j+1]+=c[i][j]/10;
			c[i][j]%=10;
		}
		while (l<=53){
			c[i][l+1]+=c[i][l]/10;
			c[i][l]%=10;
			l++;
		}
		l--;
	}
}
int main(){
	scanf("%d%d",&k,&p);
	memset(a,0,sizeof(a));
	int x=0;
	while (p>0){
		a[x++]=p%2; p>>=1;
	}
	x--;
	pre();
	for (int i=0;i<=x;i++){
		if (a[i]){
			for (int j=1;j<=54;j++){
				ans[j]+=c[i][j];
				ans[j+1]+=ans[j]/10;
				ans[j]%=10;
			}
		}
	}
	int l=54;
	while (!ans[l]) l--;
	for (int i=l;i>=1;i--) printf("%d",ans[i]);
	return 0;
}
