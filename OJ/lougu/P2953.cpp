#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i=(a);i<(b);++i)
bool f[1000005];
int n;
int max_dig(int x)
{
    int ret = 0;
    while(x){
        ret = max(ret, x % 10);
        x /= 10;
    }
    return ret;
}
int min_dig(int x)
{
    int ret = 9999;
    while(x){
        if (x % 10 != 0) ret = min(ret, x % 10);
        x /= 10;
    }
    return ret;
}
int main()
{
    f[0] = true, f[10] = true;
    REP(i,1,10) f[i] = false;
    REP(i,10,1000005)
    {
        bool f1 = false, f2 = false, g1 = false, g2 = false;
        int a = i - min_dig(i),b = i - max_dig(i);
        if (f[a - min_dig(a)]) f1 = true;
        if (f[a - max_dig(a)]) f2 = true;
        if (f[b - min_dig(b)]) g1 = true;
        if (f[b - max_dig(b)]) g2 = true;
        if ((f1 && g1) || (f1 && g2) || (f2 && g1) || (f2 && g2)) f[i] = true;
    }
    scanf("%d",&n);
    while(scanf("%d",&n) != EOF)
    {
        if (f[n]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
