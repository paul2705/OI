#include<cstdio>
#define M 100500
#define ll long long
using namespace std;
ll sum[M],f[M],d[M],q[M];
int n,k,head=0,tail=1;
void put(int j){
    d[j]=f[j-1]-sum[j];
    if(j>=k+1&&d[j-k-1]==q[head]) head++;
    while(head<tail&&d[j]>q[tail-1]) tail--;
    q[tail++]=d[j];
}
int main(){
    scanf("%d%d",&n,&k);
    sum[0]=0; f[0]=0; d[0]=0; q[0]=0;
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        sum[i]=sum[i-1]+x;
    }
    for(int i=1;i<=n;i++){
        put(i);
        f[i]=q[head]+sum[i];
    }
    printf("%lld",f[n]);
    return 0;
}
