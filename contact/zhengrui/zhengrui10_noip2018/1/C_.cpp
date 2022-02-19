#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
string s,t,ans;
int T,n,f[505][505];
int dfs(int len,int l,int r){
	if (f[l][r]!=-1) return f[l][r];
	if (l>r) return f[l][r]=1;
	for (int i=r-len;i>=l;i-=len){
		if (dfs(len,l,i)&&dfs(len,i+1,r)) return f[l][r]=1;
	}
	if (s[r]==t[(r-l)%len+1]) return f[l][r]=dfs(len,l,r-1);
	return f[l][r]=0;
}
string min(string a,string b){
	if (a=="") return b;
	if (a.size()<b.size()) return a;
	if (a.size()>b.size()) return b;
	for (int i=0;i<b.size();i++){
		if (a[i]<b[i]) return a;
		if (a[i]>b[i]) return b;
	}
	return a;
}
int main(){
	scanf("%d",&T);
	while (T--){
		for (int i=0;i<1000;i++) ans+=' ';
		cin>>s;
		n=(int)s.size();
		s=' '+s;
		for (int len=1;len<=n;len++){
			if (n%len) continue;
			for (int i=1;i<=n-len+1;i++){
				t=' '+s.substr(i,len);
				memset(f,-1,sizeof(f));
				if (dfs(len,1,n)) ans=min(ans,t);
//				cout<<t<<" "<<ans<<endl;
			}
		}
//		cout<<ans<<endl;
		ans.erase(ans.begin());
		cout<<ans<<endl;
	}
	return 0;
}
