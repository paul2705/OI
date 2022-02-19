 #include<queue>
 #include<cstdio>
 #include<vector>
 #include<cstring>
 #include<iostream>
 #include<algorithm>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define ul unsigned long long
#define ll long long
const ll maxn=2001000;
bool vis[2001010];
vector<ll> p;
void init(){
    ll n=maxn;
    memset(vis,1,sizeof(vis));
    vis[1]=0;
    vis[2]=1;
    p.push_back(2); 
    for(int i=4;i<=n;i+=2) vis[i]=0;
    for(ll i=3;i*i<=n;i+=2){
        if(vis[i]){

            for(ll j=i*i;j<=n;j+=i) vis[j]=0;
        }
    }
    for(int i=3;i<=maxn;i+=2){
        if(vis[i]) p.push_back(i); 
    }
    p.push_back(maxn); 
}
int alpha[maxn]={0};
void add_alpha_fact(int n){
    for(int i=0;p[i]<=n;i++){
        int res=n;
        while(res>0){
            res/=p[i];
            alpha[i]+=res;
        }
    }
}
void sub_twice_alpha_fact(int n){
    for(int i=0;p[i]<=n;i++){
        int res=n;
        while(res>0){
            res/=p[i];
            alpha[i]-=(res+res);
        }
    }
}
void sub_alpha(int n){
    for(int i=0;p[i]<=n;i++){
        while(n%p[i]==0){
            n/=p[i];
            alpha[i]--;
        }
    }
}
void katalan(int n){
    add_alpha_fact(2*n);
    sub_twice_alpha_fact(n);
    sub_alpha(n+1);
}
int main(){
    init();
    int cnt,cur,n=0;
    ll ha;
    cin>>cnt>>ha;
    while(cnt--){
        scanf("%d",&cur);
        if(cur>0) n++;
    }
    if(n==0){
        cout<<"TerriblePlace";
        return 0;
    }
    katalan(n);
    ll ans=1;
    rep(i,0,p.size() -1){
        while(alpha[i]--){
            ans=(ans*p[i])%ha;
        }
    }
    cout<<ans;
    return 0;
}
