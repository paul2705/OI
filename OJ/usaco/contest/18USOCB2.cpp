#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int a[150],loc[150],lis[150];
int main(){
	freopen("milkorder.in","r",stdin);
	freopen("milkorder.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1,x;i<=k;i++){
		scanf("%d",&x); scanf("%d",&loc[x]);
		if (x==1){ printf("%d\n",loc[x]); fclose(stdin); fclose(stdout); return 0; }
		lis[loc[x]]=x;
	}
	int r=m,b,j; bool flag=false;
	for (int i=n;i>0;i--){
//		printf("%d %d %d\n",i,a[r],loc[a[r]]);
		if (lis[i]>0) continue;
		if (loc[a[r]]==0&&r>0) lis[i]=a[r--];
		else if (loc[a[r]]<i) i=loc[a[r--]];
		if (a[r+1]==1){ 
			flag=true;
			j=r;
			for (j=r;j>0;j--) if (lis[a[j]]>0) break;
			b=r;
			break;
		} 
	}
//	for (int i=1;i<=n;i++) cout<<lis[i]<<" ";
//	cout<<endl; 
	if (flag){
		int cnt=0;
		for (int i=a[j]+1;i<a[b+1];i++){
			if (lis[i]>0) continue;
			if (cnt==b-j){
				printf("%d\n",i);
				break;
			}
			cnt++;
		}
		fclose(stdin); fclose(stdout);
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (lis[i]==0){ printf("%d\n",i); break; }
	fclose(stdin); fclose(stdout);
	return 0;
}
