#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define mo 100003
const int MAXN=2e3+5;
int f[MAXN][MAXN],v[MAXN];
int a,b,c,d,k,ans;
int main(){
//	cout<<MAXN<<endl;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
	for (int i=1;i<=c;i++) v[i]=d,f[i][0]=1;
	for (int i=1;i<=a;i++) v[c+i]=d+b,f[c+i][0]=1;
	f[0][0]=1;
	for (int j=1;j<=a+c;j++){
		for (int i=1;i<=k;i++){
			f[j][i]=(f[j-1][i]+f[j-1][i-1]*(v[j]-i+1))%mo;
		}
	}
	printf("%d\n",f[a+c][k]);
	return 0;
}
