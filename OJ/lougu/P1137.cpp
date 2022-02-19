#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int d[100001];
vector<int> en[100001];
int dp(int now){
    if(d[now]!=-1) return d[now];
    d[now]=1;
    for(int i=0;i<en[now].size();i++)
        d[now]=max(d[now],dp(en[now][i])+1);
    return d[now];
}
int main(){
    int n,m;
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    for(int i=1,a,b;i<=m;i++){
        cin>>a>>b;
        en[b].push_back(a);
    }
    cout<<'a'<<endl;
    for(int i=1;i<=n;i++) printf("%d\n",dp(i));
    return 0;
} 
