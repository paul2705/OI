#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e6+6;
int n,m,a[MAXN];
vector<int> lis[MAXN];
int ans,col[MAXN];
void merge(int x,int y){
    for (int i=0;i<lis[col[x]].size();i++){
        int pos=lis[col[x]][i];
        if (a[pos-1]==col[y]) ans--;
        if (a[pos+1]==col[y]) ans--;
    }
    for (int i=0;i<lis[col[x]].size();i++){
        int pos=lis[col[x]][i];
        lis[col[y]].push_back(pos);
        a[pos]=col[y];
    }
    lis[col[x]].clear();
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        col[a[i]]=a[i];
        lis[a[i]].push_back(i);
        if (a[i]!=a[i-1]) ans++;
    }
    for (int i=1;i<=m;i++){
        int op,x,y;
        scanf("%d",&op);
        if (op==1){
            scanf("%d%d",&x,&y);
			if (x==y) continue;
			int szx=lis[col[x]].size();
            int szy=lis[col[y]].size();
            if (szx>szy) swap(col[x],col[y]);
            merge(x,y);
        }
        else {
            printf("%d\n",ans);
        }
    }
    return 0;
}


