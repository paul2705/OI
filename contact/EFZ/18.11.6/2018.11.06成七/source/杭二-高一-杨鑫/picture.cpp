#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define int ll
#define file(x)freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define rt register int
#define l putchar('\n')
#define ll long long
#define r read()
using namespace std;
inline ll read(){
    ll x = 0; char zf = 1; char ch = getchar();
    while (ch != '-' && !isdigit(ch)) ch = getchar();
    if (ch == '-') zf = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); return x * zf;
}
void write(ll y){if(y<0)putchar('-'),y=-y;if(y>9)write(y/10);putchar(y%10+48);}
void writeln(const ll y){write(y);putchar('\n');}
int i,j,k,m,n,x,y,z,cnt;
int a[2000010],b[2000010];
ll f[2000010]; 
char c[2000010];
int hqz[2000010],lqz[2000010],zqz[2000010];
int gcd(int x,int y){
	return (!y)?x:gcd(y,x%y);
}
signed main(){
	file("picture");

	int n1=r,m1=r;
	scanf("%s",c+1);
	for(rt i=1;i<=n1*m1;i++)a[i]=c[i]-'0';
	int n2=r,m2=r;
	scanf("%s",c+1);
	for(rt i=1;i<=n2*m2;i++)b[i]=c[i]-'0';
	
	for(rt i=1;i<=n1;i++){
		hqz[i*m1-m1+1]=a[i*m1-m1+1];
		for(rt j=2;j<=m1;j++)hqz[i*m1-m1+j]=hqz[i*m1-m1+j-1]+a[i*m1-m1+j];	
		for(rt j=1;j<=m1;j++)lqz[i*m1-m1+j]=lqz[max(0ll,i*m1-m1-m1+j)]+a[i*m1-m1+j];
		for(rt j=1;j<=m1;j++){
			if(i!=1)zqz[i*m1-m1+j]+=zqz[i*m1-m1-m1+j];
			if(j!=1)zqz[i*m1-m1+j]+=zqz[i*m1-m1+j-1];
			if(i!=1&&j!=1)zqz[i*m1-m1+j]-=zqz[i*m1-m1-m1+j-1];
			zqz[i*m1-m1+j]+=a[i*m1-m1+j];
		}
		
	}
	ll lcmn=(ll)n1*n2/gcd(n1,n2),lcmm=(ll)m1*m2/gcd(m1,m2);
	ll sizen1=lcmn/n1,sizen2=lcmn/n2,sizem1=lcmm/m1,sizem2=lcmm/m2,ans=0;
	for(rt i=1;i<=n2;i++)
	for(rt j=1;j<=m2;j++){
		ll plx=sizen2*i,ply=sizem2*j,v=0;
		int gsx=plx/sizen1,gsy=ply/sizem1;
		if(gsx&&gsy)v=zqz[gsx*m1-m1+gsy]*sizen1*sizem1;
		if(gsx)v+=lqz[gsx*m1-m1+gsy+1]*(ply-ply/sizem1*sizem1)*sizen1;
		if(gsy)v+=hqz[gsx*m1+gsy]*(plx-plx/sizen1*sizen1)*sizem1;
		if(gsx<n1||gsy<m1)v+=a[gsx*m1+gsy+1]*(ply-ply/sizem1*sizem1)*(plx-plx/sizen1*sizen1);
		f[i*m2-m2+j]=v;
	
		if(i>1)v-=f[i*m2-m2-m2+j];
		if(j>1)v-=f[i*m2-m2+j-1];
		if(i>1&&j>1)v+=f[i*m2-m2-m2+j-1];
		if(b[i*m2-m2+j])ans+=v;
		else ans+=sizen2*sizem2-v;
		
	}
	writeln(ans);
	return 0;
}

