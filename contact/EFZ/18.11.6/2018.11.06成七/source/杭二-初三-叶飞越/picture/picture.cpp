#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,nn,mm,nnn,mmm;
ll ans;
int a[35][35],b[35][35];
char ch;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	int i,j,x,y,xx,yy;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n*m;i++){
		ch=getchar();
		while(ch!='0'&&ch!='1') ch=getchar();
		a[(i-1)/m+1][(i-1)%m+1]=(ch&1)?1:0;
	}
	scanf("%d %d",&nn,&mm);
	for(i=1;i<=nn*mm;i++){
		ch=getchar();
		while(ch!='0'&&ch!='1') ch=getchar();
		b[(i-1)/mm+1][(i-1)%mm+1]=(ch&1)?1:0;
	}
	nnn=n*nn/gcd(n,nn),mmm=m*mm/gcd(m,mm),ans=0;
	for(i=1;i<=nnn;i++) for(j=1;j<=mmm;j++){
		x=(i-1)/(nnn/n)+1,y=(j-1)/(mmm/m)+1;
		xx=(i-1)/(nnn/nn)+1,yy=(j-1)/(mmm/mm)+1;
		if(a[x][y]==b[xx][yy]) ans++;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1 2
01
2 1
01

2 2
0111
3 3
000000001

*/
