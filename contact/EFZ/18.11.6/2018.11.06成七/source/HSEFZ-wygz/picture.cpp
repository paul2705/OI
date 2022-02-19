#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+5;
ll a,b,c,d,ans;
vector<ll> s1[maxn],s2[maxn];
char s[maxn];
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
ll n,m;
void solve1() {
	ans=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (s1[(i-1)/(n/a)+1][(j-1)/(m/b)+1]==
				s2[(i-1)/(n/c)+1][(j-1)/(m/d)+1])
				ans++;
		}
	}
	printf("%lld\n",ans);
}
ll F(ll A,ll B,int E) {
	if (A>c||B>d) return 0;
	if (A<0||B<0) return 0;
	ll res=s2[A][B];
	if (E) return res;
	return A*B-res;
}
ll f(ll A,ll B,ll C,ll D,int E) {
	return F(C,D,E)-F(A-1,D,E)-F(C,B-1,E)+F(A-1,B-1,E);
}
ll g(ll x) {
	return max(0LL,x);
}
void solve2() {
	for (int i=1;i<=c;i++)
	for (int j=1;j<=d;j++)
		s2[i][j]+=s2[i-1][j]+s2[i][j-1]-s2[i-1][j-1];
	ans=0;
	ll x1,y1,x2,y2;
	ll X1,Y1,X2,Y2;
	ll A,B,C,D,tmp;
	for (ll i=1;i<=a;i++)
	for (ll j=1;j<=b;j++) {
		x1=(i-1)*(n/a)+1;
		x2=i*(n/a);
		y1=(j-1)*(m/b)+1;
		y2=j*(m/b);
		X1=(x1/(n/c))*(n/c)+1;
		X2=(x2/(n/c))*(n/c);
		Y1=(y1/(m/d))*(m/d)+1;
		Y2=(y2/(m/d))*(m/d);
		A=(X1-1)/(n/c)+1;
		B=X2/(n/c);
		C=(Y1-1)/(m/d)+1;
		D=Y2/(m/d);
		if (A&&B&&C&&D)
			tmp=f(A,C,B,D,s1[i][j])*min((n/a)*(m/b),(n/c)*(m/d));
		else tmp=0;
		if (f(A-1,C-1,A-1,C-1,s1[i][j]))
		 	tmp+=g(Y1-y1)*g(X1-x1);
		if (f(A-1,D+1,A-1,D+1,s1[i][j]))
			tmp+=g(y2-Y2)*g(X1-x1);
		if (f(B+1,C-1,B+1,C-1,s1[i][j]))
			tmp+=g(Y1-y1)*g(x2-X2);
		if (f(B+1,D+1,B+1,D+1,s1[i][j]))
			tmp+=g(y2-Y2)*g(x2-X2);
		if (C<=D) {
			tmp+=f(min(A,B),C-1,max(A,B),C-1,s1[i][j])*g(Y1-y1)*(m/d);
			tmp+=f(min(A,B),D+1,max(A,B),D+1,s1[i][j])*g(y2-Y2)*(m/d);
		}
		if (A<=B) {
			tmp+=f(A-1,min(C,D),A-1,max(C,D),s1[i][j])*g(X1-x1)*(n/c);
			tmp+=f(B+1,min(C,D),B+1,max(C,D),s1[i][j])*g(x2-X2)*(n/c);
		}
		ans+=tmp;
	}
	printf("%lld\n",ans);
}
int main() {
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	read(a); read(b);
	scanf("%s",s+1);
	for (int j=0;j<=b;j++) s1[0].push_back(0);
	for (int i=1;i<=a;i++) {
		s1[i].push_back(0);
		for (int j=1;j<=b;j++)
			s1[i].push_back(s[(i-1)*b+j]-'0');
	}
	read(c); read(d);
	scanf("%s",s+1);
	for (int j=0;j<=d;j++) s2[0].push_back(0);
	for (int i=1;i<=c;i++) {
		s2[i].push_back(0);
		for (int j=1;j<=d;j++)
			s2[i].push_back(s[(i-1)*d+j]-'0');
	}
	n=a/gcd(a,c)*c;
	m=b/gcd(b,d)*d;
	if (a<=30&&b<=30&&c<=30&&d<=30) solve1();
	else solve2();
	return 0;
}
