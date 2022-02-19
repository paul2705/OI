#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e6+6;
int a[MAXN],b[MAXN],c[MAXN*2];
int n,ans=-1,len[MAXN*2];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) a[i+n]=a[i];
	for (int i=1;i<=2*n;i++) b[i]=a[i]-a[i-1];
	for (int i=1,j=1;i<=4*n&&j<=2*n;i+=2,j++){
		c[i]=b[j]; c[i+1]=1e9;
	}
	c[0]=1e9; c[4*n+1]=1e8;
	len[0]=1;
	int pos=0,r=1;
	for (int i=1;i<=4*n;i++){
		if (i<r) len[i]=min(len[2*pos-i],r-i);
		while (len[i]+i<=4*n&&i-len[i]>=0&&c[len[i]+i]==c[i-len[i]]) len[i]++;
		if (i+len[i]>r) pos=i,r=i+len[i];
	}
	bool f=0;
//	for (int i=1;i<=4*n;i++) cout<<c[i]<<" "; cout<<endl;
//	for (int i=1;i<=4*n;i++) cout<<len[i]<<" "; cout<<endl;
	for (int i=1;i<=4*n;i++){
		if (c[i]==1e9||c[i]==1e8) continue;
		if (len[i]-1>=n-1){
//			cout<<i<<" "<<n<<endl;
			f=1;
			ans=(i+1)/2-(n-1)/2-2;
			break;
		}
	}
	if (f==0) printf("IMPOSSIBLE\n");
	else if (ans==-1) printf("0\n");
	else printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
