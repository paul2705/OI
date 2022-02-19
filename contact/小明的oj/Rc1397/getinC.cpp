#include<bits/stdc++.h>
using namespace std;
 
int t;
int n, m;
int a, b, c, d;
 
int random1(int mod) {
    if(mod == 0)return 1;
    return (rand() + 1) % mod + 1;
}
 
int main() {
    freopen("profit.in", "w", stdout);
    srand(time(NULL));
    t = 100000; 
    printf("%d\n", t);
    for(int i = 0; i < t; ++i) {
        n = random1(100000);
        printf("%d\n", n);
        for(int k = 2; k <= n; ++k)printf("%d %d\n", random1(k - 1), k);
        printf("\n");
    }
}
