#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define LL long long
using namespace std;
inline int read(){
    static int x; static bool f; x = 0,f = 0; static char c; c = getchar();
    while (!isdigit(c)) {if (c == '-') f = 1;c = getchar();}
    while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
    return f ? -x : x;
}
inline void write(LL x){
    if (x < 0) putchar('-'),x = -x;
    if (x > 9) write(x/10); putchar(x%10+'0');
}
inline void writeln(LL x){ write(x),putchar('\n'); }
const int N = 3000005,M = (N/10)+5; const LL INF = 1ll * N * (1e9 + 1);

namespace work{
	int n,a[N],size,m,l[N],r[N],cur[N],Lg[M]; LL v[N];
	LL mx[N],mn[N];
	
	LL premx[N],sufmx[N];
	LL premn[N],sufmn[N];
	LL smx[M][20],smn[M][20];
	
	inline void Build(int nn){
		int i,j,k,tmp;
		n = nn;
		size = min(30,n);
		for (i = 1; i <= n; ++i) cur[i] = (i-1) / size + 1,a[i] = read(),v[i] = v[i-1] + a[i];
		m = cur[n];
		for (i = 1; i <= m; ++i){
			l[i] = (i-1) * size + 1; r[i] = i * size;
			if (r[i] > n) r[i] = n;
			premx[l[i]] = premn[l[i]] = mx[i] = mn[i] = v[l[i]];
			for (j = l[i] + 1; j <= r[i]; ++j){
				mx[i] = max(mx[i],v[j]);
				mn[i] = min(mn[i],v[j]);
				premx[j] = max(premx[j-1],v[j]);
				premn[j] = min(premn[j-1],v[j]); 
			}
			sufmx[r[i]] = sufmn[r[i]] = v[r[i]];
			for (j = r[i] - 1; j >= l[i]; --j){
				sufmx[j] = max(sufmx[j+1],v[j]);
				sufmn[j] = min(sufmn[j+1],v[j]);
			}
			smx[i][0] = mx[i];
			smn[i][0] = mn[i];
		}
		Lg[0] = 0;
		for (i = 1; i <= m; ++i){
			Lg[i] = Lg[i-1] + 2;
			while ((1ll << Lg[i]) > i) --Lg[i];
		}
		for (j = 1; (1 << j) <= m; ++j){
			tmp = (1 << (j-1));
			for (i = 1; i <= m; ++i){
				smx[i][j] = smx[i][j-1];
				smn[i][j] = smn[i][j-1];
				k = i + tmp; 
				if (k <= n){
					smx[i][j] = max(smx[i][j],smx[k][j-1]);
					smn[i][j] = min(smn[i][j],smn[k][j-1]);
				}
			}
		}
	}
	inline LL RMQmx(int l,int r){
		static int len; len = r - l + 1; len = Lg[len];
		return max(smx[l][len],smx[r-(1<<len)+1][len]);
	}
	inline LL RMQmn(int l,int r){
		static int len; len = r - l + 1; len = Lg[len];
		return min(smn[l][len],smn[r-(1<<len)+1][len]);
	}
	inline LL Max(int l,int r){
		static int curl,curr,i; LL ans;
		curl = cur[l],curr = cur[r];
		if (curl == curr){
			for (ans = v[l],i = l + 1; i <= r; ++i) ans = max(ans,v[i]);
			return ans;
		}
		if (curl + 1 == curr) return max(sufmx[l],premx[r]);
		return max(max(sufmx[l],premx[r]),RMQmx(curl+1,curr-1));
	}
	inline LL Min(int l,int r){
		static int curl,curr,i; LL ans;
		curl = cur[l],curr = cur[r];
		if (curl == curr){
			for (ans = v[l],i = l + 1; i <= r; ++i) ans = min(ans,v[i]);
			return ans;
		}
		if (curl + 1 == curr) return min(sufmn[l],premn[r]);
		return min(min(sufmn[l],premn[r]),RMQmn(curl+1,curr-1));
	}
	
	LL mx1,mn1,mx2,mn2;
	inline LL Query(int l,int r,int i,int val){
		if (i == l){
			mx1 = Max(l,r) - v[l-1],mn1 = Min(l,r) - v[l-1];
			return max(val * mx1,val * mn1);
		}
		if (i == r){
			mx1 = v[r] - Min(l-1,r-1),mn1 = v[r] - Max(l-1,r-1);
			return max(val * mx1,val * mn1);
		}
		mx1 = Max(i,r) - Min(l-1,i-1);
		mn1 = Min(i,r) - Max(l-1,i-1);
		return max(val * mx1,val * mn1);
	}
}

int n,a[N],l[N],r[N]; LL val[N];
int st[N],top;

inline bool Small(int x,int y){ // x < y;
	return a[x] == a[y] ? x < y : a[x] < a[y];
}

int main(){
	int i;
	freopen("1.in","r",stdin);
	n = read();
	for (i = 1; i <= n; ++i) a[i] = read();
	work::Build(n);
	top = 0;
	for (i = 1; i <= n; ++i){
		if (!top) st[++top] = i;
		else{
			while (top && Small(i,st[top])) r[st[top]] = i - 1,--top;
			st[++top] = i;
		}
	}
	while (top) r[st[top]] = n,--top;
	
	top = 0;
	for (i = n; i ; --i){
		if (!top) st[++top] = i;
		else{
			while (top && Small(i,st[top])) l[st[top]] = i + 1,--top;
			st[++top] = i;
		}
	}
	while (top) l[st[top]] = 1,--top;
	
	LL ans = work::Query(l[1],r[1],1,a[1]),vv;
	for (i = 2; i <= n; ++i) vv = work::Query(l[i],r[i],i,a[i]),ans = max(ans,vv);
	writeln(ans);
	return 0;
}
