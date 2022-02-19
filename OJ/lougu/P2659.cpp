#include<cstdio>
#define maxn 2000005
struct node{
    long long idx,val;
}a[maxn],st[maxn];
int N,top;
long long ans;
long long Max(long long x,long long y){return x>y?x:y;}
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;++i){
        scanf("%lld",&a[i].val),a[i].idx=i;
        if(!top)st[++top]=a[i];
        else {
            while(st[top].val>a[i].val){ans=Max(ans,st[top].val*(i-st[top-1].idx-1));top--;}
            st[++top]=a[i];
        }
    }
    for(int i=1;i<=top;++i){
        ans=Max(ans,(N-st[i-1].idx)*st[i].val);
    }
    printf("%lld",ans);
    return 0;
}
