#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Add(x,y) ((x+=y)>=mod?x-=mod:0)
using namespace std;
const int mod=998244353;
int n,m,len[25],Val[(1<<20)+10],s[(1<<20)+10][55],num[(1<<20)+10][55],ap[(1<<20)+10],pw[1010],tot,wy,ans,lb;
char a[25][55];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",a[i]+1);
		len[i]=strlen(a[i]+1);
		m=max(m,len[i]);
		ap[1<<(i-1)]=len[i];
		for(int j=1;j<=len[i];++j)
			s[1<<(i-1)][j]=(isdigit(a[i][j])?a[i][j]-'0'+1:-1);
		for(int j=len[i];j>=1;--j)
			num[1<<(i-1)][j]=num[1<<(i-1)][j+1]+(a[i][j]=='?');
	}
	Val[0]=-1,pw[0]=1,ap[0]=1e9;
	for(int i=1;i<(1<<n);++i){
		lb=(i&(-i));
		ap[i]=min(ap[lb],ap[i-lb]);
		for(int j=1;j<=m;++j)
			num[i][j]=num[lb][j]+num[i-lb][j];
	}
	for(int i=1;i<=n*m;++i)pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1;i<=m;++i)s[0][i]=-1;
	for(int i=1;i<(1<<n);++i){
		Val[i]=(i&1?-1:1)*Val[i>>1],lb=(i&(-i)),tot=0,wy=1;
		for(int j=1;j<=ap[i]+1;++j){
			s[i][j]=(s[lb][j]&s[i-lb][j]);
			if(!s[i][j]||ap[i]<j){
				tot=(tot+1ll*wy*pw[num[i][j]]%mod*j)%mod;
				break;
			}
			else if(s[i][j]==-1)
				tot=(tot+1ll*wy*(pw[num[i][j]-num[i][j+1]]-2)%mod*pw[num[i][j+1]]%mod*j)%mod,Add(wy,wy);
			else tot=(tot+1ll*wy*(pw[num[i][j]-num[i][j+1]]-1)%mod*pw[num[i][j+1]]%mod*j)%mod;
		}
		ans=(ans+1ll*Val[i]*tot*pw[num[(1<<n)-1][1]-num[i][1]]%mod+mod)%mod;
	}
	printf("%d",ans);
	return 0;
}
