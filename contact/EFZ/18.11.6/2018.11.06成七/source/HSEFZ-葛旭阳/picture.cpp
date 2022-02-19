#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 100005
#define jump goto 
#define a(x,y) _a[w1*(x-1)+y]
#define b(x,y) _b[w2*(x-1)+y]

int _a[MAXN],_b[MAXN];

int w1,h1,w2,h2;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int getc(){
	char c;
	cin>>c; 
	return c-'0';
}

int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&h1,&w1);for(int i=1;i<=h1*w1;i++)_a[i]=getc();
	scanf("%d%d",&h2,&w2);for(int i=1;i<=h2*w2;i++)_b[i]=getc();
	
	int dw1=w1/gcd(w1,w2),dw2=w2/gcd(w1,w2),dh1=h1/gcd(h1,h2),dh2=h2/gcd(h1,h2);
	
	int ans=0;
	int i2=1;
	for(int i1=1;i1<=h1;i1++){
		sti:
		int j2=1;
		int sh=min(i1*dh2,i2*dh1)-max((i1-1)*dh2,(i2-1)*dh1);
		for(int j1=1;j1<=w1;j1++){
			stj: 
			int sw=min(j1*dw2,j2*dw1)-max((j1-1)*dw2,(j2-1)*dw1);
			if(a(i1,j1)==b(i2,j2))ans+=sh*sw;
			if(j2*dw1<=j1*dw2){
				j2++;
				jump stj;
			}
		}
		if(i2*dh1<=i1*dh2){
			i2++;
			jump sti;
		}
	}
	
	cout<<ans;
}
