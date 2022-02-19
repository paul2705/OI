#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
int h1, w1, h2, w2;
char s1[maxn], s2[maxn];

int gcd(int x, int y){
    return (y==0) ? x : gcd(y, x%y);
}
int up(int x, int y){//upper bound integer division
    return (x % y == 0) ? x/y : (x/y+1);
}
#define rep(i, st, ed) for(register int i = (st); i <= (ed); ++i)
#define per(i, st, ed) for(register int i = (st); i >= (ed); --i)

ll ans = 0;
namespace brute{
    char m1[55][55], m2[55][55];

    void work(){
        rep(i, 1, h1) rep(j, 1, w1) m1[i][j] = s1[(i-1)*w1+j];
        rep(i, 1, h2) rep(j, 1, h2) m2[i][j] = s2[(i-1)*w2+j];

        int h = h1*h2/gcd(h1, h2), w =w1*w2/gcd(w1, w2);
        int dh1 = h/h1, dw1 = w/w1, dh2 = h/h2, dw2 = w/w2;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                if(m1[up(i, dh1)][up(j, dw1)] == m2[up(i, dh2)][up(j, dw2)]){
                    ans++;
                }
            }
        }
        printf("%lld\n", ans);
    }
            
};
signed main(){
    freopen("picture.in", "r", stdin);
    freopen("picture.out", "w", stdout);

    scanf("%d%d", &h1, &w1);
    scanf("%s", s1+1);
    
    scanf("%d%d", &h2, &w2);
    scanf("%s", s2+1);
    brute::work();

    return 0;
}
