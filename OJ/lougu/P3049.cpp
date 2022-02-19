#include<bits/stdc++.h>
#define Ll long long
using namespace std;
const Ll N=1e5+5;
Ll n,x,y,ans,m1,m2,z;
priority_queue<Ll>Q1;
priority_queue<Ll>Q2;
int main()
{
    scanf("%lld%lld%lld%lld",&n,&x,&y,&z);
    for(Ll j=1;j<=n;j++){
        scanf("%lld%lld",&m1,&m2);
        if(m1<m2)
            for(Ll i=1;i<=m2-m1;i++)
                if(Q1.empty()||j*z-Q1.top()>=x){
                    ans+=x;Q2.push(x+j*z);
                }else{
                    Ll v=Q1.top();Q1.pop();
                    ans+=j*z-v;Q2.push(j*z*2-v);
                }
        else
            for(Ll i=1;i<=m1-m2;i++)
                if(Q2.empty()||j*z-Q2.top()>=y){
                    ans+=y;Q1.push(y+j*z);
                }else{
                    Ll v=Q2.top();Q2.pop();
                    ans+=j*z-v;Q1.push(j*z*2-v);
                }
    }
    printf("%lld",ans);
}
