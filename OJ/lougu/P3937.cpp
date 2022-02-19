#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=3000010;
int n, t, k, a[N], ans;
int main(){
    scanf("%d%d%d",&n,&t,&k);
    for(int i=1; i <= n; i++) scanf("%d",&a[i]); ans=a[k];
    for(int i=1; i <= t; i++) if((t|i) == t){
        int next=i+k; next%=n; 
        if(!next) next=n;
        ans^=a[next];
    }
    printf("%d", ans);
    return 0;
}
