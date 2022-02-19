#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
int mp[MAXN][MAXN];
int n,m,a[MAXN],rd[MAXN];
int d[MAXN],mx=1;
priority_queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,s;i<=m;i++){
		scanf("%d",&s);
//		cout<<s<<endl;
		for (int j=1;j<=s;j++) scanf("%d",&a[j]);
		int l=1;
		for (int j=a[1]+1;j<a[s];j++){
//			cout<<j<<" "<<l<<" "<<a[l+1]<<endl;
			if (j==a[l+1]){ l++; continue; }
//			cout<<j<<endl;
			for (int k=1;k<=s;k++){
				if (mp[j][a[k]]==0) mp[j][a[k]]=1,rd[a[k]]++;
			}
		}
	}
//	for (int i=1;i<=n;i++) cout<<rd[i]<<" "; cout<<endl;
    int tot=n;
    while (tot>0){
        mx++;      
//		cout<<tot<<" "<<mx<<endl;
		int w[n],nu=0;
        for(int x=1;x<=n;x++){
            if(!rd[x]){
                tot--;
                w[++nu]=x;
            }
        }
        for(int x=1;x<=nu;x++){
            for(int y=1;y<=n;y++){
                if(mp[w[x]][y]) rd[y]--;
            }
        }
    }
	printf("%d\n",mx);
	return 0;
}
