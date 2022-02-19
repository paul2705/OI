#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 10000001
int n, q;
int fth[N];
bool tag[N];
int r, ans[N];
int main(){
    tag[1] = true;
    scanf("%d%d", &n, &q);
    for(int i = 1, u, v; i < n; i ++)
    scanf("%d%d", &u, &v), fth[v] = u;
    for(int i = 1; i <= q; i ++){
        char c; int u;
        scanf("\n%c %d", &c, &u);
        if(c == 'C')tag[u] = true;
        else{
            while(!tag[u])u = fth[u];
            ans[++ r] = u;
        }
    }
    for(int i = 1; i <= r; i ++)
    printf("%d\n", ans[i]);
    return 0;
}
