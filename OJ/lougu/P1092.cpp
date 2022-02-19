#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=50;
int a[MAXN][MAXN],g[MAXN][MAXN];
int n,ans[MAXN];
bool use[MAXN];
char c1[MAXN],c2[MAXN],c3[MAXN];
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int lcm(int a,int b){ return a/gcd(a,b)*b; }
int main(){
	scanf("%d",&n);
	cin>>c1>>c2>>c3;
	for (int i=0;i<n;i++){
//		cout<<c1[i]<<" "<<c2[i]<<" "<<c3[i]<<endl;
		a[n-i-1][c1[i]-'A']++;
		a[n-i-1][c2[i]-'A']++;
		a[n-i-1][c3[i]-'A']--;
		if (i!=0) g[i][i-1]=-1;
		g[i][i]=n;
	}
//	cout<<"done"<<endl;
//	for (int i=0;i<n;i++){
//		for (int j=0;j<n;j++) printf("(%d %d) ",a[i][j],g[i][j]);
//		cout<<endl;
//	}
	for (int k=0,r=0;k<n&&r<n;k++,r++){
		int mx=k;
		for (int i=k+1;i<n;i++){
			if (abs(a[i][r])>abs(a[mx][r])) mx=i;
		}
		if (mx!=k) swap(a[k],a[mx]),swap(g[k],g[mx]);
		if (!a[k][r]){ k--; continue; }
		for (int i=0;i<n;i++){
			if (i!=k&&a[i][r]!=0){
				int lm=lcm(a[i][r],a[k][r]);
				int ta=lm/a[i][r],tb=lm/a[k][r];
				for (int j=0;j<n;j++){
					g[i][j]=ta*g[i][j]-tb*g[k][j];
					a[i][j]=ta*a[i][j]-tb*a[k][j];
				}
			}
		}
	}
//	cout<<"done"<<endl;
//	for (int i=0;i<n;i++){
//		for (int j=0;j<n;j++) printf("(%d %d) ",a[i][j],g[i][j]);
//		cout<<endl;
//	}
	for (int s=0;s<(1<<n);s++){
//		cout<<s<<" "<<n<<endl;
		bool f=true; memset(use,0,sizeof(use));
		for (int i=0;i<n;i++){
//			cout<<i<<" "<<n<<endl;
			ans[i]=0;
			for (int j=0;j<n;j++){
				if (s&(1<<j)) ans[i]+=g[i][j];
			}
//			cout<<n<<endl;
//			cout<<a[i][i]<<" ";
			if (ans[i]%a[i][i]||ans[i]/a[i][i]<0||
				ans[i]/a[i][i]>=n||use[ans[i]/a[i][i]]){ f=0; break; }
			ans[i]/=a[i][i];
//			cout<<n<<" "<<ans[i]<<endl;
			use[ans[i]]=1;
		}
//		cout<<s<<endl;
		if (f){
			for (int i=0;i<n;i++) printf("%d ",ans[i]);
			cout<<endl;
			return 0;
		}
//		cout<<"exit"<<endl;
	}
	return 0;
}
