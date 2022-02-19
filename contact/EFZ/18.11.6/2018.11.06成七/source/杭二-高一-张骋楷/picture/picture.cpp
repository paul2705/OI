#include<cstdio> 
#include<iostream> 
#include<cstring> 
#include<cmath> 
#include<cctype> 
#include<algorithm> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define interesting int
const int N=1E6+10;
int n1,n2,m1,m2;
char a[N],b[N];
ll ans=0,h1,h2;
inline int gcd(int x,int y){
	while(int t=x%y){
		x=y;
		y=t;
	}return y;
}
inline ll sol(int x,int y){
	int now=y*m2-m2+1;ll sum=h2;ll tot=0;
	for(int i=x*m1-m1+1;i<=x*m1;i++){
		ll res=h1;
		while(res){
			ll gg=(a[i]==b[now]);
			ll ff=min(res,sum);
			tot+=gg*ff;
			res-=ff;
			sum-=ff;
			if(!sum){
				now++;
				sum=h2;
			}
		}
	}
//	printf("*********%d %d %lld\n",x,y,tot);
	return tot;
}
int main(){
    freopen("picture.in","r",stdin);
    freopen("picture.out","w",stdout);
	scanf("%d%d%s",&n1,&m1,a+1);
	scanf("%d%d%s",&n2,&m2,b+1);
//	printf("%d\n",strlen(b+1));
	ll x=1ll*n1*n2/gcd(n1,n2),y=1ll*m1*m2/gcd(m1,m2);
	h1=y/m1,h2=y/m2;
	int now=1;ll sum=x/n2;
	for(int i=1;i<=n1;i++){
		ll res=x/n1;
		while(res){
			ll gg=sol(i,now);
			ll ff=min(res,sum);
			ans+=gg*ff;
			res-=ff;
			sum-=ff;
			if(!sum){
				now++;
				sum=x/n2;
			}
		}
	}
	printf("%lld\n",ans);
    return 0;
} 
