#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m;
int num[101000];
int ma[303000];
int s[101000];
int t[101000];
int ans1,ans2;
int len;

int c[101000];

int find(int x){
	int l=1,r=len,mid;
	mid=(l+r)>>1;
	while(l<=r){
		mid=(l+r)>>1;
		if(x>c[mid]) l=mid+1;
		else		 r=mid-1;
	}
	return l;
}

int main(){
		freopen("new.in","r",stdin);
		freopen("new.out","w",stdout);
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++){
				scanf("%d",&num[i]);
				ma[num[i]]=i;
		}
		ans1=1;
		ans2=1;
		for(int i=1; i<=m; i++){
				for(int j=1; j<=n; j++) scanf("%d",&s[j]);
				t[0]=0;
				for(int j=1; j<=n; j++){
					s[j]=ma[s[j]];
					if(s[j]==0) continue;
					t[j]=1;
					if(s[j]==s[j-1]+1) t[j]=t[j-1]+1;
					ans2=max(ans2,t[j]);
				}
				len=0;
				for(int j=1; j<=n; j++) c[j]=0;
				for(int j=1; j<=n; j++){
					if(s[j]==0) continue;
					int k=find(s[j]);
					c[k]=s[j];
					len=max(len,k);
				}
				ans1=max(ans1,len);
		}
		cout<<ans1<<endl;
		cout<<ans2<<endl;
}
