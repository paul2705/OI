#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mod 1000000007
#define pb push_back
#define fir first
#define sec second
const int N = 1e5 + 10;

int qpow(int x,int y,int p = mod) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % p;
        x = 1ll * x * x % p;
        y >>= 1;
    }

    return res;
}

int Inv(int x) {
    return qpow(x , mod - 2);
}

struct Instack {
    int prex , prey;
    int prexsz , preysz;
};

stack<Instack> s;
int ans = 1;
struct UFS {
    int n , fa[N] , sz[N];


    void init() {
        for (int i = 1; i <= n; i++) fa[i] = i , sz[i] = 1;
    }
    int F(int x) {
        if (fa[x] == x) return x;
        return F(fa[x]);
    }

    void merge(int x,int y) {
        x = F(x);y = F(y);
        if (sz[x] > sz[y]) swap(x , y);
	
        s.push((Instack) {x , y , sz[x] , sz[y]});
        
        ans = 1ll * ans * Inv(sz[x]) % mod;
        ans = 1ll * ans * Inv(sz[y]) % mod;
        fa[x] = y;
        sz[y] += sz[x];
        ans = 1ll * ans *  sz[y] % mod;
    }
    void pop() {
        Instack cur = s.top();
        s.pop();
        ans = 1ll * ans * Inv(sz[cur.prey]) % mod;
        fa[cur.prex] = cur.prex;
        sz[cur.prex] = cur.prexsz;
        sz[cur.prey] = cur.preysz;
        ans = 1ll * ans * sz[cur.prex] % mod;
        ans = 1ll * ans * sz[cur.prey] % mod;
    }
} ufs;

int res[N];
vector<pii> G[N << 2];
int cnt[N << 2];
void insert(int o,int l,int r,int ql,int qr,const pii &E) {
    if (ql <= l && r <= qr) {
        G[o].pb(E);
        return;
    }
    int mid = (l+r)>>1;
    if (ql <= mid) insert(o << 1 , l , mid , ql , qr , E);
    if (mid < qr ) insert(o << 1 | 1 , mid + 1 , r , ql , qr , E);
}
void solve(int o,int l,int r) {

    for (int i = 0; i < G[o].size(); i++){
        if (ufs.F(G[o][i].fir) != ufs.F(G[o][i].sec) ) {
            cnt[o]++;
            ufs.merge(G[o][i].fir , G[o][i].sec);
        }
    }
    if (l == r) {
        res[l] = ans;
        for (int i = 1;i <= cnt[o];i++) ufs.pop();
    } else {
        int mid = (l + r ) >> 1;
        solve(o << 1 , l , mid);
        solve(o << 1 | 1 , mid + 1 , r);
   		for (int i = 1;i <= cnt[o];i++) ufs.pop();
	}
}


map<pii,int> exi;
map<pii,int>::iterator it;

int n , m;

int len , dg[20];
void write(int x){
	if(x==0){putchar(48);return;}
	len = 0;
	while(x>0){dg[++len]=x%10;x/=10;}
	for(int i=len;i>=1;i--)putchar(dg[i]+48);
}
inline int read(){
	int x = 0;char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = (x << 1) + (x << 3) + c - '0' , c = getchar();
	return x;
}
int main () {
	freopen("geography.in","r",stdin);
	
	freopen("geography.out","w",stdout);
    scanf("%d%d",&n,&m);
    ufs.n = n;
    ufs.init();
    for (int i = 1; i <= m; i++) {
        int op = read() , x = read() , y = read();
        pii tmp = make_pair(x , y);
        if (op == 1) {
            exi[tmp] = i;
        } else {
            insert(1 , 1 , m , exi[tmp] , i - 1 , tmp );
            exi[tmp] = 0;
        }
    }
    for (it = exi.begin(); it != exi.end(); it++){
        if (it->second) {
            insert(1 , 1 , m , it->second , m , it->first );
        }
	}
    solve(1 , 1 , m);

    for (int i = 1; i <= m; i++) write(res[i]) , putchar('\n');

    return 0;
}
