#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=110;
int f[MAXM],sg[MAXN],Hash[MAXN];
int n,m;
void getSG(int m){
	memset(sg,0,sizeof(sg));
	for (int i=1;i<MAXN;i++){
		memset(Hash,false,sizeof(Hash));
		for (int j=0;j<m&&f[j]<=i;j++){
			Hash[sg[i-f[j]]]=true;
		}
		for (int j=0;j<MAXN;j++){
			if (!Hash[j]){
				sg[i]=j;
				break;
			}
		}
	}
}
int SG_dfs(int x){
	if (sg[x]!=-1) return sg[x];
	memset(Hash,false,sizeof(Hash));
	for (int i=0;i<m&&f[i]<=x;i++){
		SG_dfs(x-f[i]);
		Hash[sg[x-f[i]]]=true;
	}
	for (int i=0;i<MAXN;i++){
		if (!Hash[i]) return sg[x]=i;
	}
	return 0;
}
int main(){
	while (cin>>m&&m){
		for (int i=0;i<m;i++) cin>>f[i];
		sort(f,f+m);
		getSG(m);
		cin>>n;
		while (n--){
			int num,sum=0;
			cin>>num;
			for (int i=0;i<num;i++){
				int each; cin>>each;
				sum^=sg[each];
			}
			if (sum) cout<<"W";
			else cout<<"L";
		
		}
		cout<<endl;
	}
	return 0;
}
