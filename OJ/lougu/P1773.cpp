#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int INF=1e6;
int fx[MAXN][60],fn[MAXN][60],s[MAXN][MAXN];
int a[MAXN],cnt,n,mod;
char ss[MAXN];
int main(){
	cin>>ss; cnt=strlen(ss);
	scanf("%d",&mod);
	for (int i=0;i<cnt;i++) a[i+1]=(ss[i]-'0');
	for (int i=1;i<=cnt;i++){
//		cout<<a[i]<<endl;
		s[i][i]=a[i]%mod;
		for (int j=i+1;j<=cnt;j++){
			s[i][j]=(s[i][j-1]*10+a[j])%mod;
		}
	}
	for (int i=1;i<=cnt;i++){
		for (int k=0;k<mod;k++) fn[i][k]=INF;
		fn[i][s[1][i]]=1;
	}
//	cout<<s[1][cnt]<<endl;
	for (int i=1;i<=cnt;i++){
		for (int k=0;k<mod;k++){
			for (int j=1;j<i;j++){
				fn[i][k*s[j+1][i]%mod]=min(fn[i][k*s[j+1][i]%mod],fn[j][k]+1);
			}
		}
	}
	for (int i=0;i<mod;i++){
		if (fn[cnt][i]<INF){
			printf("%d %d",i,fn[cnt][i]-1);
			break;
		}
	}
//	cout<<" in : "<<mod<<endl;
	for (int i=mod-1;i>=0;i--){
		if (fn[cnt][i]<INF){
			printf(" %d %d\n",i,fn[cnt][i]-1);
			break;
		}
	}
	return 0;
}
