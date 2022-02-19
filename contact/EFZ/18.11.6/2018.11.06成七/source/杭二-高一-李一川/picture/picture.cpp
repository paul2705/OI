#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
#include<cmath>
#define LL long long
#define N (1000005)
using namespace std;
template <typename T> void read(T&t) {
	t=0;
	bool fl=true;
	char p=getchar();
	while (!isdigit(p)) {
		if (p=='-') fl=false;
		p=getchar();
	}
	do {
		(t*=10)+=p-48;p=getchar();
	}while (isdigit(p));
	if (!fl) t=-t;
}
char c1[N],c2[N];
int h1,w1,h2,w2,h,w,stx,sty,enx,eny,op;
LL x,xx,y,yy,ans;
int f[N];
int gcd(int a,int b){
	while (a%b!=0){
		int tmp=b;
		b=a%b;
		a=tmp;
	}
	return b;
}
inline int sum(int x,int y){
	return f[x*w2-w2+y]; 
}
inline LL get(LL a,LL b,LL aa,LL bb){
	//printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld\n",x,y,xx,yy,a,b,aa,bb,(min(xx,aa)-max(x,a)+1)*(min(yy,bb)-max(y,b)+1));
	return (min(xx,aa)-max(x,a)+1)*(min(yy,bb)-max(y,b)+1);
}
LL query(int x,int xx,int y,int yy){
	if (xx<x||yy<y) return 0;
	int tot=sum(xx,yy)-sum(xx,y-1)-sum(x-1,yy)+sum(x-1,y-1);
	//printf("%d %d %d %d %d\n",x,xx,y,yy,tot);
	LL ret=get(1ll*(x-1)*h1/h+1,1ll*(y-1)*w1/w+1,1ll*xx*h1/h,1ll*yy*w1/w)/(xx-x+1)/(yy-y+1);
	if (op) return ret*tot;
	else return ret*((xx-x+1)*(yy-y+1)-tot);
}

int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	read(h1),read(w1);
	scanf("%s",c1+1); 
	read(h2),read(w2);
	scanf("%s",c2+1);
	h=gcd(h1,h2);
	w=gcd(w1,w2);
	for (int i=1;i<=h2;i++){
		for (int j=1;j<=w2;j++){
			f[i*w2-w2+j]=sum(i-1,j)+sum(i,j-1)-sum(i-1,j-1)+c2[i*w2-w2+j]-'0';
		}
	}
	for (int i=1;i<=h1;i++){
		for (int j=1;j<=w1;j++){
			x=1ll*(i-1)*h2/h+1,xx=1ll*i*h2/h;
			y=1ll*(j-1)*w2/w+1,yy=1ll*j*w2/w;
			stx=(int)ceil(x*1.0/(h1/h)),enx=(int)ceil(xx*1.0/(h1/h));
			sty=(int)ceil(y*1.0/(w1/w)),eny=(int)ceil(yy*1.0/(w1/w));
			op=c1[i*w1-w1+j]-'0';
			if (stx==enx&&sty==eny){
				ans+=query(stx,enx,sty,eny);
				continue;
			}
			if (stx==enx){
				ans+=query(stx,stx,sty,sty),ans+=query(stx,stx,sty+1,eny-1),ans+=query(stx,stx,eny,eny);
				continue;
			}
			if (sty==eny){
				ans+=query(stx,stx,sty,sty),ans+=query(stx+1,enx-1,sty,sty),ans+=query(enx,enx,sty,sty);
				continue;
			}
			ans+=query(stx,stx,sty,sty),ans+=query(stx,stx,sty+1,eny-1),ans+=query(stx,stx,eny,eny);
			ans+=query(stx+1,enx-1,sty,sty),ans+=query(stx+1,enx-1,sty+1,eny-1),ans+=query(stx+1,enx-1,eny,eny);
			ans+=query(enx,enx,sty,sty),ans+=query(enx,enx,sty+1,eny-1),ans+=query(enx,enx,eny,eny);
		}
	}
	printf("%lld",ans);
	return 0;
}

