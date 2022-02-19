#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}

const int N = 1000005;
int h1, w1, h2, w2, hh1, hh2, ww1, ww2;
ll h, w, ans;
char *s[N], *t[N], ss[N], tt[N];
inline int gcd(int x, int y){ return y?gcd(y, x%y):x;}
int main() {
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	read(h1), read(w1);
	while(isspace(ss[0]=read()));
	for(int i=1; i<h1*w1; ++i) ss[i]=read();
	for(int i=0; i<h1; ++i) s[i]=ss+i*w1;
	read(h2), read(w2);
	while(isspace(tt[0]=read()));
	for(int i=1; i<h2*w2; ++i) tt[i]=read();
	for(int i=0; i<h2; ++i) t[i]=tt+i*w2;

	h=(ll)h1*h2/gcd(h1, h2);
	hh1=h/h1, hh2=h/h2;
	w=(ll)w1*w2/gcd(w1, w2);
	ww1=w/w1, ww2=w/w2;
	for(int i=0; i<h1; ++i) for(int j=0; j<w1; ++j){
		for(int x=i*hh1/hh2; x<=(i*hh1+hh1-1)/hh2; ++x)
			for(int y=j*ww1/ww2; y<=(j*ww1+ww1-1)/ww2; ++y){
				if(s[i][j]==t[x][y])
					ans+=(min(i*hh1+hh1, x*hh2+hh2)-max(i*hh1, x*hh2))
						*(min(j*ww1+ww1, y*ww2+ww2)-max(j*ww1, y*ww2));
				// printf("--%d %d %d %d %d %d %d %d\n",
				// i, j, x, y, x*hh2, x*hh2+hh2, y*ww2, y*ww2+ww2);
			}
		// printf(">>%lld\n", ans);
	}
	return printf("%lld", ans), 0;
}
