#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<int> a[1000010],b[1000010];
ll n1,m1,n2,m2;
ll extn1,extn2,extm1,extm2,gn,gm;
ll cnt=0;
char s[1000010];
ll gcd(ll a,ll b)
{
	if(a<b)swap(a,b);
	return b?gcd(b,a%b):a;
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%lld%lld",&n1,&m1);
	scanf("%s",s);
	for(int i=0;i<n1;i++)
	{
		for(int j=0,ti;j<m1;j++)
		{
			ti=s[i*m1+j]-'0';
			a[i].push_back(ti);
		}
	}
	scanf("%lld%lld",&n2,&m2);
	scanf("%s",s);
	for(int i=0;i<n2;i++)
	{
		for(int j=0,ti;j<m2;j++)
		{
//			scanf("%d",&ti);
			ti=s[i*m2+j]-'0';
			b[i].push_back(ti);
		}
	}
	gn=gcd(n1,n2);
	extn1=n2/gn;extn2=n1/gn;
	gm=gcd(m1,m2);
	extm1=m2/gm;extm2=m1/gm;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m1;j++)
		{
			ll txl=extn1*i,txr=extn1*(i+1)-1;
			ll tyl=extm1*j,tyr=extm1*(j+1)-1;
			ll lx_in_b=txl/extn2,rx_in_b=txr/extn2;
			ll ly_in_b=tyl/extm2,ry_in_b=tyr/extm2;
			for(int k=lx_in_b;k<=rx_in_b;k++)
			{
				for(int l=ly_in_b;l<=ry_in_b;l++)
				{
					ll nxl=extn2*k,nxr=extn2*(k+1)-1;
					ll nyl=extm2*l,nyr=extm2*(l+1)-1;
					if(b[k][l]==a[i][j])
					cnt+=(min(nxr,txr)-max(nxl,txl)+1)*(min(nyr,tyr)-max(nyl,tyl)+1);
				}
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}
