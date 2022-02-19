#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXL=1e3+5;
const int MAXN=20;
struct rec{
	int a[MAXL];
} f[MAXN],tmp,one;
int n,d;
//prt(rec ans){}
void prt(rec& ans,bool flag){
	for (int i=ans.a[0];i>0;i--) printf("%d",ans.a[i]);
	if (flag) printf("\n");
	else printf(" ");
}
rec mul(rec& ans,rec& x){
	for (int i=0;i<=1000;i++) tmp.a[i]=0;
	tmp.a[0]=ans.a[0]+x.a[0]-1;
	for (int i=1;i<=ans.a[0];i++){
		int now=ans.a[i];
		for (int j=1;j<=x.a[0];j++){
			tmp.a[i+j-1]+=now*x.a[j];
			tmp.a[i+j]+=tmp.a[i+j-1]/10;
			tmp.a[i+j-1]%=10;
		}
//		prt(tmp,1);
	}
	while (tmp.a[tmp.a[0]+1]!=0){
		int now=(++tmp.a[0]);
		tmp.a[tmp.a[0]+1]=tmp.a[now]/10;
		tmp.a[now]%=10;
	}
//	prt(ans,0); prt(x,0);
//	prt(tmp,1);
//	cout<<"out"<<endl;
	return tmp;
}
void pow(rec &ans,rec x,int n){
	ans=x;
	n--;
	while (n){
		if (n&1) ans=mul(ans,x);
		x=mul(x,x);
		n>>=1;
	}
//	prt(ans,1);
//	cout<<"out"<<endl;
}
void dec(rec& ans,rec x){
	int len=max(ans.a[0],x.a[0]);
	ans.a[0]=len;
	for (int i=1;i<=len;i++){
		ans.a[i]-=x.a[i];
		while (ans.a[i]<0){
			ans.a[i+1]--;
			ans.a[i]+=10;
		}
	}
	while (ans.a[ans.a[0]]==0) ans.a[0]--;
//	cout<<"out"<<endl;
}
void ins(rec& ans,rec& x){
	int len=max(ans.a[0],x.a[0]);
	ans.a[0]=len;
	for (int i=1;i<=len;i++){
		ans.a[i]+=x.a[i];
		while (ans.a[i]>9){
			ans.a[i+1]++;
			ans.a[i]-=10;
		}
	}
//	cout<<ans.a[0]<<" "<<ans.a[ans.a[0]+1]<<endl;
	while (ans.a[ans.a[0]+1]>0){
//		cout<<"in"<<endl;
		ans.a[ans.a[0]+2]+=ans.a[ans.a[0]+1]/10;
		ans.a[++ans.a[0]]%=10;
	}
}
int main(){
	one.a[0]=one.a[1]=1;
	scanf("%d%d",&n,&d);
	if (d==0){
		printf("1\n");
		return 0;
	}
	f[0].a[0]=f[0].a[1]=1;
	for (int i=1;i<=d;i++){
		pow(f[i],f[i-1],n);
		ins(f[i],one);
//		prt(f[i],1);
	}
	dec(f[d],f[d-1]);
	prt(f[d],1);
	return 0;
}
