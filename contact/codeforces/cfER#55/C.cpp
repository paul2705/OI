#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
vector<int> a[MAXN],s[MAXN];
int n,m,ub;
int ans,sum;
bool cmp1(int a,int b){ return a>b; }
bool cmp(vector<int> a,vector<int> b){ return a.size()>b.size(); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
	}
	for (int i=1;i<=m;i++) sort(a[i].begin(),a[i].end(),cmp1);
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=m;i++){
		for (int j=0;j<a[i].size();j++){
			s[i].push_back((j>0?s[i][j-1]:0)+a[i][j]);
//			cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
		}
	}
//	cout<<"fuck"<<endl;
	for (int i=0;i<a[1].size();i++){
		sum=0;
		for (int j=1;j<=m;j++){
			if (a[j].size()<=i) continue;
//			cout<<j<<" "<<i<<" "<<sum<<" "<<s[j][i]<<endl;
			if (s[j][i]<0) continue;
			sum+=s[j][i];
//			cout<<":: "<<sum<<endl;
			ans=max(ans,sum);
		}
//		cout<<ans<<endl;
	}
	printf("%d\n",ans<0?0:ans);
	return 0;
}
