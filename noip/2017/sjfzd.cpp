#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
bool use[MAXN];
int s[MAXN],a[MAXN],top;
int n,T;
char tim[MAXN],ch[MAXN];
int main(){
	scanf("%d",&T);
	while (T--){
		top=0; bool f=1;
		scanf("%d",&n);
		for (int i=0;i<=150;i++) use[i]=0;
		cin>>tim; s[0]=a[0]=0; use['n']=1;
		for (int i=1;i<=n;i++){
			char c=getchar(); while (c!='F'&&c!='E') c=getchar();
			if (c=='F'){
				ch[++top]=getchar(); while (ch[top]<'a'||ch[top]>'z') ch[top]=getchar();
				char c1[5],c2[5];
				int f1=0,f2=0,l=0,r=0;
				cin>>c1>>c2;
//				cout<<i<<" "<<c1<<" "<<c2<<endl;
				if (use[ch[top]]) f=0;
				if (c1[0]=='n') f1=2;
				else f1=1;
				if (c2[0]=='n') f2=2;
				else f2=1;
//				cout<<f1<<" "<<f2<<endl;
				if (f1==1&&f2==1){
					for (int i=0;i<strlen(c1);i++){
						l=l*10+c1[i]-'0';
					}
					for (int i=0;i<strlen(c2);i++){
						r=r*10+c2[i]-'0';
					}
				}
				if (f1<f2) s[top]=1;
				else if (f1==f2){
					if (f1==1&&f2==1&&l>r) s[top]=-1;
					else s[top]=0;
				}
				else s[top]=-1;
				a[top]=0;
				use[ch[top]]=1;
			}
			else{
				int old=top;
				top--;
				if (top<0) f=0;
				use[ch[old]]=0;
				if (s[old]>=0) a[top]=max(a[top],s[old]+a[old]);
			}
		}
//		cout<<top<<endl;
		if (top>=1) f=0;
		if (!f){
			printf("ERR\n");
			continue;
		}
		int ret=0;
		int l=0,r=0;
		for (int i=0;i<strlen(tim);i++){
			if (tim[i]>='0'&&tim[i]<='9'){
				l=i;
				break;
			}
		}
		for (int i=strlen(tim)-1;i>=0;i--){
			if (tim[i]>='0'&&tim[i]<='9'){
				r=i;
				break;
			}
		}
		for (int i=l;i<=r;i++){
			ret=ret*10+tim[i]-'0';
		}
		if (s[0]>=0) s[0]+=a[0];
		else s[0]=0;
//		cout<<ret<<" "<<s[0]<<endl;
		if ((ret==s[0]&&tim[l-1]!='(')||(tim[l-1]=='('&&s[0]==0)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
