#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
struct rec{
long long d,p;
}a[100005];
priority_queue <rec> q;
bool cmp(rec a,rec b){
  return a.d<b.d;
}
bool operator < (rec a,rec b){
     return a.p>b.p;
}
int main(){    
    long long n,ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].d,&a[i].p);
    sort(a+1,a+1+n,cmp); 
    for(int i=1;i<=n;i++)
        if (a[i].d<=q.size()){
          if (q.top().p<a[i].p) 
             ans+=a[i].p-q.top().p,q.pop(),q.push(a[i]); 
        }
        else q.push(a[i]),ans+=a[i].p;
    printf("%lld",ans);
}
