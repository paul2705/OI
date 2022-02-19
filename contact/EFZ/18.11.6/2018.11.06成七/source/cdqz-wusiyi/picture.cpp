#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1000010;
int h1,w1,h2,w2;
char s1[N],s2[N];

int g(char *x,int l1,char *y,int l2) {
	if(l1<l2) swap(x,y),swap(l1,l2);
	ll L=1ll*l1*l2/__gcd(l1,l2);
	int t1=L/l1,t2=L/l2,res=0;
	for(int i=0,j=0,k=0,a=-1,b=-1;i<L;i=min(j,k)) {
		while(i>=j) j+=t1,a++;
		while(i>=k) k+=t2,b++;
		if(x[a]==y[b]) res+=min(j,k)-i;
	}
	return res;
}

int main() {
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d%s%d%d%s",&h1,&w1,s1,&h2,&w2,s2);
	if(h1<h2) swap(h1,h2),swap(w1,w2),swap(s1,s2);
	ll H=h1*h2/__gcd(h1,h2);
	int t1=H/h1,t2=H/h2;ll res=0;
	for(int i=0,j=0,k=0,a=-1,b=-1;i<H;i=min(j,k)) {
		while(i>=j) j+=t1,a++;
		while(i>=k) k+=t2,b++;
		res+=1ll*g(s1+a*w1,w1,s2+b*w2,w2)*(min(j,k)-i);
	}
	printf("%lld\n",res);
	return 0;
}
