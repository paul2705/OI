#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline void judge(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
}
inline int gcd(int a,int b){
	while(b){
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
char s1[1000005],s2[1000005];
int main(){
	judge();
	int h1,w1;
	scanf("%d%d",&h1,&w1);
	scanf("%s",s1);
	int h2,w2;
	scanf("%d%d",&h2,&w2);
	scanf("%s",s2);
	long long h=1ll*h1*h2/gcd(h1,h2),w=1ll*w1*w2/gcd(w1,w2);
	// printf("%lld %lld\n",h,w);
	long long ans=0;
	for(int i=0;i<h1;i++)
		for(int j=0;j<w1;j++){
			long long hl=i*(h/h1),hr=(i+1)*(h/h1)-1;
			long long wl=j*(w/w1),wr=(j+1)*(w/w1)-1;
			// printf("%lld %lld %lld %lld\n",hl,hr,wl,wr);
			for(int k=hl/(h/h2);k<=hr/(h/h2);k++)
				for(int p=wl/(w/w2);p<=wr/(w/w2);p++)if(s1[i*w1+j]==s2[k*w2+p]){
					// printf("%d %d\n",k,p);
					long long hl0=k*(h/h2),hr0=(k+1)*(h/h2)-1;
					long long wl0=p*(w/w2),wr0=(p+1)*(w/w2)-1;
					// printf("%lld %lld %lld %lld\n",hl0,hr0,wl0,wr0);
					if(min(hr0,hr)-max(hl0,hl)+1>0&&min(wr0,wr)-max(wl0,wl)+1>0)
						ans+=(min(hr0,hr)-max(hl0,hl)+1)*(min(wr0,wr)-max(wl0,wl)+1);
				}
		}
	printf("%lld\n",ans);
	return 0;
}