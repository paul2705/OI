#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, st, ed) for(register int i = (st); i <= (ed); ++i)
#define per(i, st, ed) for(register int i = (st); i >= (ed); --i)

const int maxn = 5005;
int n, m, p;
int a[maxn], ans;
int  pos(int x, int y) {
    return (m)*(x-1)+y;
}
void check(){
    int cnt = 0;
    rep(i, 1, n) rep(j, 1, m) {
        int mx1 = 0, mx2 = 0;
        rep(k, 1, n) mx1 = max(a[pos(k, j)], mx1);
        rep(k, 1, m) mx2 = max(a[pos(i, k)], mx2);
        if(mx1==mx2 && mx1 == a[pos(i, j)]) cnt++;
    }
    if(cnt == 1) ans++;
}

signed main(){
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &p); 
//    dfs(1);
    ans = 0;
    rep(i, 1, n*m) a[i] = i;
    do{
        check();
    }    while(next_permutation(a+1, a+n*m+1));
    printf("%d\n", ans);

    return 0;
}
