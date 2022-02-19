#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> G[1005],surd,suru;
struct rec{
    ll x,y,z;
} che[1005];
bool vs[1005],flag;
ll n,m,T,h,r;
double dist(ll i,ll j){
    return (che[i].x-che[j].x)*(che[i].x-che[j].x)+
    (che[i].y-che[j].y)*(che[i].y-che[j].y)+
    (che[i].z-che[j].z)*(che[i].z-che[j].z);
}
void dfs(ll u){
    for (ll i=0;i<G[u].size();i++){
        ll v=G[u][i];
        if (!vs[v]){
            vs[v]=true;
            dfs(v);
        }
    }
}
int main(){
    //freopen("cheese.in","r",stdin);
    //freopen("cheese.out","w",stdout);
    scanf("%lld",&T);
    while (T>0){
        T--;
        scanf("%lld%lld%lld",&n,&h,&r);
        flag=false;
        surd.clear(); suru.clear();
        for (ll i=0;i<1005;i++) G[i].clear();
        memset(vs,false,sizeof(vs));
        for (ll i=1;i<=n;i++) {
            scanf("%lld%lld%lld",&che[i].x,&che[i].y,&che[i].z);
            if (che[i].z-r<=0) surd.push_back(i);
            if (che[i].z+r>=h) suru.push_back(i);
        }
        if (surd.size()==0||suru.size()==0){
            printf("No\n");
            continue;
        }
        for (ll i=1;i<=n;i++){
            for (ll j=i+1;j<=n;j++){
                if (dist(i,j)<=4*r*r){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        for (ll i=0;i<surd.size();i++){
            if (!vs[surd[i]]){
                vs[surd[i]]=true;
                dfs(surd[i]);
            }
        }
        for (ll i=0;i<suru.size();i++){
            if (vs[suru[i]]) flag=true;
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
