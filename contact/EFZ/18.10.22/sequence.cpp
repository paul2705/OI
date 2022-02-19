#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=8e6+6;
int a[MAXN],b[MAXN],n,pos,loc,len[MAXN];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) a[i+n]=a[i];
	b[0]=1e9; int j=1;
	for (int i=1;i<=n*4;i+=2){
		b[i]=a[j]-a[j-1]; j++;
		b[i+1]=1e9;
		cout<<b[i]<<" "<<b[i+1]<<" ";
	}
	b[n*4+1]=1e8;
	int r=0;
	pos=0; loc=0; len[0]=1;
	for (int i=1;i<=n*4;i++){
		if (i<r) len[i]=min(len[pos*2-i],r-i+1); 
		loc=max(i,i+len[i]-1);
		if (i*2-loc>=0&&loc<=n*4&&b[loc]==b[i*2-loc]){
			while (b[loc]==b[i*2-loc]) loc++; loc--;
		}
		len[i]=loc-i+1;
		if (loc>pos+len[pos]-1) pos=i,r=loc;
	}
	int ans=-1;
	bool f=0;
	for (int i=1;i<=n*4;i++){
		if (b[i]==1e9||b[i]==1e8) continue;
		cout<<len[i]<<" ";
	}
	cout<<endl;
	for (int i=1;i<=n*4;i++){
		if (b[i]==1e9||b[i]==1e8) continue;
//		cout<<len[i]<<" ";
		if (len[i]/2>=n/2){
			f=1;
			ans=(i+1)/2-n/2-1;
			break;
		}
	}
	cout<<endl;
	if (ans==-1&&f) printf("0\n");
	else if (n==2) printf("0\n");
	else if (ans==-1) printf("IMPOSSIBLE\n");
	else printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
