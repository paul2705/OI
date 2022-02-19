#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=8e6+6;
int a[MAXN],b[MAXN],n,pos,loc,len[MAXN];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequencew.out","w",stdout);
	scanf("%d",&n);
//	cout<<n<<endl;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) a[i+n]=a[i];
	b[0]=1e9; int j=1;
	for (int i=1;i<=n*4;i+=2){
		b[i]=a[j]-a[j-1]; j++;
//		cout<<b[i]<<" ";
		b[i+1]=1e9;
	}
//	cout<<endl;
	b[n*4+1]=1e8;
    int pos=0,R=0;
    for (int i=1;i<=n*4;i++)
    {
        if (i<R) len[i]=min(len[2*pos-i],R-i); else len[i]=1;
        while (1<=i-len[i]&&i+len[i]<=n*4&&b[i-len[i]]==b[i+len[i]]) len[i]++;
        if (i+len[i]>R) {pos=i;R=i+len[i];}
    }
	int ans=-1;
	bool f=0;
	for (int i=1;i<=n*4;i++){
		if (b[i]==1e9||b[i]==1e8) continue;
		if (len[i]-1>=n-1){
//			cout<<i<<" "<<len[i]/2<<" "<<n/2<<endl;
			f=1;
			ans=(i+1)/2-n/2-1;
			break;
		}
	}
//	for (int i=1;i<=n*4;i++){
//		if (b[i]==1e9||b[i]==1e8) continue;
//		cout<<len[i]<<" ";
//	}
//	cout<<endl;
	if (ans==-1&&f) printf("0\n");
	else if (n==2) printf("0\n");
	else if (ans==-1) printf("IMPOSSIBLE\n");
	else printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
