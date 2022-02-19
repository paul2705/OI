#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5e2+5;
int a[MAXN][MAXN];
int n;
char s[MAXN];
int sum(int x,int y,int xx,int yy){
	return a[xx][yy]-a[x-1][yy]-a[xx][y-1]+a[x-1][y-1];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		for (int j=1;j<=len;j++){
			int x=s[j]-'0';
			if (s[j]>='A'&&s[j]<='F') x=s[j]-'A'+10;
			for (int k=1;k<=4;k++){
				a[i][(j-1)*4+k]=(x>>(4-k))&1;
			}
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++) printf("%d",a[i][j]);
//		cout<<endl;
//	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	}
	for (int i=n;i>=1;i--){
		if (n%i!=0) continue;
		bool f=1;
		for (int j=1;j<=n&&f;j+=i){
			for (int k=1;k<=n&&f;k+=i){
				int res=sum(j,k,j+i-1,k+i-1);
				if (res>0&&res<i*i) f=0;
			}
		}
		if (f){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;	
}
