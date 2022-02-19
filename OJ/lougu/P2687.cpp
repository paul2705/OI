#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
int f[MAXN],cnt[MAXN][500];
int n,a[MAXN],ans;
void add(int x,int y){
//	cout<<__func__<<endl;
//	cout<<x<<" "<<y<<endl;
	int k=0;
	for (int i=1;i<=max(cnt[x][0],cnt[y][0]);i++){
		cnt[x][i]+=cnt[y][i]+k;
		k=cnt[x][i]/10; cnt[x][i]%=10;
	}
//	cout<<"done"<<endl;
	cnt[x][0]=max(cnt[x][0],cnt[y][0]);
	while (k>0) cnt[x][++cnt[x][0]]=k%10,k/=10;
//	cout<<cnt[x][0]<<endl;
}
void cn(int x){ memset(cnt[x],0,sizeof(cnt[x])); }
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
        f[i]=1;
        for (int j=1;j<i;j++){
            if (a[j]>a[i]) f[i]=max(f[i],f[j]+1);
        }
        ans=max(ans,f[i]);
    }
    for (int i=1;i<=n;i++){
        if (f[i]==1) cnt[i][0]=cnt[i][1]=1;
        for (int j=1;j<i;j++){
            if (f[j]+1==f[i]&&a[j]>a[i]) add(i,j);
            if (f[j]==f[i]&&a[j]==a[i]) cn(i);
        }
        if (f[i]==ans) add(MAXN-1,i);
    }
    printf("%d ",ans);
//for (int i=1;i<=49;i++) printf("%d ",cnt[MAXN-1][i]);
    for (int i=cnt[MAXN-1][0];i>0;i--) printf("%d",cnt[MAXN-1][i]);
    cout<<endl;
    return 0;
}


