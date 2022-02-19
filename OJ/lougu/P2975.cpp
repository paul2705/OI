#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll w[710000],f[710000],id[710000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    f[n]=w[n];id[n]=n;f[n+1]=0;
    for(int i=n-1;i>=1;i--){
        if(w[i]+f[id[i+1]+1]>=f[i+1]){
            f[i]=w[i]+f[id[i+1]+1];
            id[i]=i;
        }
        else{
            f[i]=f[i+1];
            id[i]=id[i+1];
        }
    }
    printf("%lld %lld\n",f[1],f[id[1]+1]);
    return 0;
}
