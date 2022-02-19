#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod1=1e9+7;
const int MAXN=1e2+5;
const int MAXS=1e5+5;
bool f[MAXS][20];
int n,pos[MAXN],tp[MAXN],l[MAXN],cnt;
char a[MAXS],b[MAXS];
ll has[MAXS],s[MAXS],s2[MAXS],pw[MAXS];
ll h1(int b,int t){
//	if (b<=t) cout<<t<<" "<<b<<" "<<(s[t]-s[b-1]*pw[t-b+1]%mod1+2*mod1)%mod1<<endl;
//	else cout<<0<<endl;
	if (b>t) return 0;
	return (s[t]-(s[b-1]*pw[t-b+1]%mod1)+2*mod1)%mod1;
}
int main(){
	scanf("%s",a+1);
	scanf("%d",&n);
	int len=1,ln=strlen(a+1);
	pw[0]=1; a[++ln]='?';
	for (int i=1;i<=100000;i++) pw[i]=pw[i-1]*26%mod1;
	s2[0]=0;
	for (int i=1;i<=ln;i++,len++){
		s2[i]=(s2[i-1]*26+a[i])%mod1;
		if (a[i]=='?'){
			pos[++cnt]=i,l[cnt]=len-1,tp[cnt]=1,len=0;
			has[cnt]=(s2[i-1]-(s2[pos[cnt-1]]*pw[l[cnt]]%mod1)+2*mod1)%mod1;
		}
		if (a[i]=='*'){
			pos[++cnt]=i,l[cnt]=len-1,tp[cnt]=2,len=0;
			has[cnt]=(s2[i-1]-(s2[pos[cnt-1]]*pw[l[cnt]]%mod1)+2*mod1)%mod1;
		}
	}
//	for (int i=1;i<=cnt;i++){
//		cout<<i<<" "<<pos[i]<<" "<<l[i]<<" "<<tp[i]<<" "<<has[i]<<endl;
//	}
	while (n--){
		scanf("%s",b+1); len=strlen(b+1)+1;
		for (int i=1;i<len;i++){
			for (int j=1;j<=cnt;j++) f[j][i]=0;
		}
		s[0]=0; f[0][0]=1;
		for (int i=1;i<len;i++) s[i]=(s[i-1]*26+b[i])%mod1;
		for (int i=0;i<=cnt;i++){
			for (int j=0;j<len;j++){
				if (f[j][i]){
					if (tp[i+1]==1){
						if (h1(j+1,j+l[i+1])==has[i+1])
							f[j+l[i+1]+1][i+1]=1;
					}
					else {
						if (h1(j+1,j+l[i+1])==has[i+1]){
							for (int k=j+l[i+1];k<len;k++){
								f[k][i+1]=1;
							}
						}
					}
				}
//				cout<<j<<" "<<i<<" "<<f[j][i]<<endl;
			}
		}
		if (f[len][cnt]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
