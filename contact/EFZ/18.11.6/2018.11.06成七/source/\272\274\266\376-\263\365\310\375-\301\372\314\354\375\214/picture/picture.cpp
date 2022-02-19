#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#define N (1000010)
#define inf (0x7f7f7f7f)
#define rg register int
#define Label puts("NAIVE")
typedef long double ld;
typedef long long LL;
typedef unsigned long long ull;
using namespace std;
int n,m,n1,m1,cnt;
LL H,W,h1,h2,w1,w2,ans;
int sum[N];
char ch,s[N],s1[N];
int gcd(int x,int y){
	if(x<y)swap(x,y);
	return y?gcd(y,x%y):x;
}
void belong(int &ansx,int &ansy,LL x,LL y){
	ansx=(x-1)/h2+1,ansy=(y-1)/w2+1;
}
//ºá 
LL queryh(int h,int l,int r,LL x,char ch){
	if(l>r)return 0;
	int L,R,cnt0,cnt1;
	L=(h-1)*m1+l,R=(h-1)*m1+r;
	cnt0=sum[R];
	if(R>m1)cnt0-=sum[R-m1];
	if(L%m1!=1)cnt0-=sum[L-1];
	if(R>m1&&L%m1!=1)cnt0+=sum[L-m1-1];
	cnt1=(r-l+1)-cnt0;
	if(ch=='0')return (LL)cnt0*(LL)x*(LL)w2;else return (LL)cnt1*(LL)x*(LL)w2;
}
//×Ý 
LL queryz(int h,int l,int r,LL x,char ch){
	if(l>r)return 0;
	int L,R,cnt0,cnt1;
	L=(l-1)*m1+h,R=(r-1)*m1+h;
	//cout<<L<<" "<<R<<endl;
	cnt0=sum[R];
	if(L>m1)cnt0-=sum[L-m1];
	if(R%m1!=1)cnt0-=sum[R-1];
	if(R%m1!=1&&L>m1)cnt0+=sum[L-m1-1];
	
	cnt1=(r-l+1)-cnt0;
	//cout<<cnt0<<" "<<cnt1<<endl;
	if(ch=='0')return (LL)cnt0*(LL)x*(LL)h2;else return (LL)cnt1*(LL)x*(LL)h2;
}
//¾ØÐÎ 
LL query(int x1,int y1,int x2,int y2,char ch){
	if(x1>x2||y1>y2)return 0;
	int Lu,Ru,Ld,Rd,cnt0,cnt1;
	Lu=(x1-1)*m1+y1,Rd=(x2-1)*m1+y2;
	Ld=(x2-1)*m1+y1,Ru=(x1-1)*m1+y2;
	cnt0=sum[Rd];
	if(Ru>m1)cnt0-=sum[Ru-m1];
	if(Ld%m1!=1)cnt0-=sum[Ld-1];
	if(Lu>m1&&(Lu%m1)!=1)cnt0+=sum[Lu-m1-1];
	cnt1=(y2-y1+1)*(x2-x1+1)-cnt0;
	if(ch=='0')return (LL)cnt0*(LL)h2*(LL)w2;else return (LL)cnt1*(LL)h2*(LL)w2;
}
LL calc(LL x1,LL y1,LL x2,LL y2,char ch,char ch1){
	//cout<<
	if(ch==ch1)return (x2-x1+1)*(y2-y1+1);
	else return 0;
}
int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&n,&m),ch=getchar();
	while(ch>'1'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='1')s[++cnt]=ch,ch=getchar();
	scanf("%d%d",&n1,&m1),ch=getchar(),cnt=0;
	while(ch>'1'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='1')s1[++cnt]=ch,ch=getchar();
	for(int i=1;i<=n1*m1;i++){
		if(i>m1)sum[i]+=sum[i-m1];
		if(i%m1!=1)sum[i]+=sum[i-1];
		if(s1[i]=='0')sum[i]++;
		if(i>m1&&i%m1!=1)sum[i]-=sum[i-m1-1];
		//cout<<i<<" "<<sum[i]<<endl;
	}
	H=1ll*n*n1/(LL)gcd(n,n1),W=1ll*m*(LL)m1/(LL)gcd(m,m1);
	h1=H/n,h2=H/n1,w1=W/m,w2=W/m1;
	//cout<<h1<<" "<<w1<<" "<<h2<<" "<<w2<<endl;
	for(int i=1;i<=n*m;i++){
		ch=s[i];
		LL x=(i-1)/m+1,y=(i-1)%m+1;
		LL x1=(x-1)*h1+1,y1=(y-1)*w1+1,x2=x*h1,y2=y*w1;
		//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		int a1,b1,a2,b2,p1,p2;
		belong(a1,b1,x1,y1),belong(a2,b2,x2,y2);
		//cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
		p1=(a1-1)*m1+b1,p2=(a2-1)*m1+b2;
		if(a1==a2&&b1==b2){
			if(ch==s1[p1])
			ans+=(x2-x1+1)*(y2-y1+1);
		}
		else if(a1==a2){
			LL yy=b1*w2;
			if(ch==s1[p1])ans+=(yy-y1+1)*(x2-x1+1);
			yy=(b2-1)*w2+1;
			if(ch==s1[p2])ans+=(y2-yy+1)*(x2-x1+1);
			ans+=queryh(a1,b1+1,b2-1,(x2-x1+1),ch);
		}
		else if(b1==b2){
			LL xx=a1*h2;
			if(ch==s1[p1])ans+=(xx-x1+1)*(y2-y1+1);
			//cout<<xx<<" "<<x1<<endl;
			xx=(a2-1)*h2+1;
			//cout<<xx<<" "<<x2<<endl; 
			if(ch==s1[p2])ans+=(x2-xx+1)*(y2-y1+1);
			//cout<<ans<<endl;
			ans+=queryz(b1,a1+1,a2-1,(y2-y1+1),ch);
		}
		else{
			ans+=query(a1+1,b1+1,a2-1,b2-1,ch);
			ans+=queryh(a1,b1+1,b2-1,(LL)a1*h2-x1+1ll,ch);
			ans+=queryh(a2,b1+1,b2-1,(LL)x2-((a2-1)*h2+1)+1ll,ch);
			ans+=queryz(b1,a1+1,a2-1,(LL)b1*w2-y1+1ll,ch);
			ans+=queryz(b2,a1+1,a2-1,(LL)y2-((b2-1)*w2+1)+1ll,ch);
			ans+=calc(x1,y1,a1*h2,b1*w2,ch,s1[p1]);
			ans+=calc(x1,(b2-1)*w2+1,a1*h2,y2,ch,s1[(a1-1)*m1+b2]);
			ans+=calc((a2-1)*h2+1,y1,x2,b1*w2,ch,s1[(a2-1)*m1+b1]);
			ans+=calc((a2-1)*h2+1,(b2-1)*w2+1,x2,y2,ch,s1[p2]);
		}
		//cout<<ans<<endl;
	}
	printf("%lld\n",ans);
}
