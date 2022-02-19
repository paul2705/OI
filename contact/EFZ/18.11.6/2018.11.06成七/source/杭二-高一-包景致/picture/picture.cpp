#include <bits/stdc++.h>
using namespace std;
#define re register int
#define rep(i,a,b) for(re i=a;i<=b;++i)
#define _ 0
template <class T>inline void read(T &x) {
	x=0; int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	x*=f;
}

int h1, w1, h2, w2, res;
char s1[2000], s2[2000];
int t1[2000][2000], t2[2000][2000];
int p[2000][2000], q[2000][2000];

int main() {
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	read(h1),read(w1);
	scanf("%s", s1+1);
	rep(i,1,h1)rep(j,1,w1)	t1[i][j]=s1[(i-1)*w1+j]-48;
	read(h2),read(w2);
	scanf("%s", s2+1);
	rep(i,1,h2)rep(j,1,w2)	t2[i][j]=s2[(i-1)*w2+j]-48;
	long long n=h1/__gcd(h1,h2)*h2, m=w1/__gcd(w1,w2)*w2;
	int o1=n/h1, o2=n/w1;
	rep(i,1,n)rep(j,1,m)	p[i][j]=t1[(i-1)/o1+1][(j-1)/o2+1];
	o1=n/h2, o2=n/w2;
	rep(i,1,n)rep(j,1,m)	q[i][j]=t2[(i-1)/o1+1][(j-1)/o2+1];
	rep(i,1,n)rep(j,1,m)if(p[i][j]==q[i][j])	++res;
	printf("%d\n",res);
	return ~~(0^_^0);
}
