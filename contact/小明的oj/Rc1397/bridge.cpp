#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=255;
const int MAXT=8005;
int T,n,f[MAXN][MAXN][MAXN];
struct rec{
	int tim,wai;
} a[MAXN],b[MAXN];
char dir[MAXN];
int main(){
	scanf("%d%d",&T,&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='W'&c!='E') c=getchar();
		dir[i]=c; 
		if (c=='W') scanf("%d%d",&a[i].tim,&a[i].wai);
		else scanf("%d%d",&b[i].tim,&b[i].wai);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=i;k--){
				 
