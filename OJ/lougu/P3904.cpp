#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[55][55][1000],n,m;
void add(int a,int b){  // f[a][b][..]=f[a-1][b-1][..]+b*f[a-1][b][..];
	int x=0; f[a][b][0]=max(f[a-1][b][0],f[a-1][b-1][0]);
	for (int i=1;i<=f[a][b][0];i++){
		f[a][b][i]=f[a-1][b][i]*b+f[a-1][b-1][i]+x;
		x=f[a][b][i]/10,f[a][b][i]%=10;
	}
	while (x) f[a][b][++f[a][b][0]]=x%10,x/=10;
//	cout<<a<<" "<<b<<endl;
//	for (int i=f[a][b][0];i>=1;i--) printf("%d",f[a][b][i]); cout<<endl;
}
int main(){
	scanf("%d%d",&n,&m);
	f[1][1][0]=f[1][1][1]=1;
	for (int i=2;i<=n;i++){
		for (int j=1;j<=min(m,i);j++){
			add(i,j);
		}
	}
	if (f[n][m][0]==0) printf("0\n");
	else for (int i=f[n][m][0];i>=1;i--) printf("%d",f[n][m][i]);
	return 0;
}
