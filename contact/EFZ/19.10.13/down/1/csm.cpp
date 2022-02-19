#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=10;
const int MAXS=35;
const int MAXT=6e3+5;
struct rec{
	string s;
	bool operator == (const rec& b) const {
		int n=s.size(),m=b.s.size();
		if (n!=m) return 0;
		for (int i=0;i<n;i++){
			if (s[i]!=b.s[i]) return 0;
		}
		return 1;
	}
} a[MAXN],ans[MAXT],tmp;
int n,cnt;
bool use[MAXN];
void dfs(int d){
	if (d==n+1){
		for (int i=1;i<=cnt;i++){
			if (ans[i]==tmp) return;
		}
//		cout<<tmp.s<<endl;
		ans[++cnt].s=tmp.s;
	}
	for (int i=1;i<=n;i++){
		if (use[i]) continue;
		int l=tmp.s.size();
		if (l==0&&a[i].s[0]=='0') continue;
		tmp.s+=a[i].s;
		use[i]=1;
		dfs(d+1);
		use[i]=0;
		l=tmp.s.size(); int r=a[i].s.size();
//		cout<<"erase: "<<tmp.s<<" ";
		tmp.s.erase(l-r,r);
//		cout<<tmp.s<<endl;
	}
}
int main(){
	freopen("csm.in","r",stdin);
	freopen("csm.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) cin>>a[i].s;
	dfs(1);
	printf("%d\n",cnt);
	fclose(stdin); fclose(stdout);
	return 0;
}
