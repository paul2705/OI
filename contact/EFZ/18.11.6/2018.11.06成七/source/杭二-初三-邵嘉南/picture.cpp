#include<bits/stdc++.h>
using namespace std;
int h1,w1,h2,w2,a[35][35],b[35][35],f1[1005][1005],ans;
int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&h1,&w1);
	for(int i=1;i<=h1;++i)
	for(int j=1;j<=w1;++j) scanf("%1d",&a[i][j]);
	scanf("%d%d",&h2,&w2);
	for(int i=1;i<=h2;++i)
	for(int j=1;j<=w2;++j) scanf("%1d",&b[i][j]);
	int t1=gcd(h1,h2);
	int t2=gcd(w1,w2);
	int g1=h2/t1,g2=w2/t2;
	for(int i=1;i<=h1;++i)
	for(int j=1;j<=w1;++j)
	{
		for(int k=(i-1)*g1+1;k<=i*g1;++k)
		for(int l=(j-1)*g2+1;l<=j*g2;++l)
		f1[k][l]=a[i][j];
	}
	g1=h1/t1; g2=w1/t2;
	for(int i=1;i<=h2;++i)
	for(int j=1;j<=w2;++j)
	{
		for(int k=(i-1)*g1+1;k<=i*g1;++k)
		for(int l=(j-1)*g2+1;l<=j*g2;++l)
		if(b[i][j]==f1[k][l]) ans++;
	} 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


