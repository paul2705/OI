#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e6+6;
int n,m,cnt,ans,c[MAXN],d[MAXN];
char a[MAXN],b[MAXN];
int use[105],ret[105];
int main(){
	freopen("mayan.in","r",stdin);
	freopen("mayan.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a>>b;
	for (int i=0;i<n;i++){
//		cout<<a[i]<<" ";
		if (a[i]>='A'&&a[i]<='Z') c[i]=a[i]-'A'+30;
		if (a[i]>='a'&&a[i]<='z') c[i]=a[i]-'a';
//		cout<<c[i]<<endl;
		use[c[i]]++; if (use[c[i]]==1) cnt++;
	}
//	cout<<cnt<<endl;
	for (int i=0;i<m;i++){
		if (b[i]>='A'&&b[i]<='Z') d[i]=b[i]-'A'+30;
		if (b[i]>='a'&&b[i]<='z') d[i]=b[i]-'a';
	}
	for (int i=0;i<n;i++){
		ret[d[i]]++;
		if (ret[d[i]]==use[d[i]]) cnt--;
		if (ret[d[i]]-1==use[d[i]]) cnt++;
	}
//	cout<<cnt<<endl;
	if (cnt==0) ans++;
	for (int i=n;i<m;i++){
		ret[d[i-n]]--;
		if (ret[d[i-n]]==use[d[i-n]]) cnt--;
		if (ret[d[i-n]]+1==use[d[i-n]]) cnt++;
		ret[d[i]]++;
		if (ret[d[i]]==use[d[i]]) cnt--;
		if (ret[d[i]]-1==use[d[i]]) cnt++;
//		cout<<cnt<<endl;
		if (cnt==0) ans++;
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
