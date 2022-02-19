#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=505;
int a[MAXN],b[MAXN];
char tmp[MAXN];
int main(){
	cin>>tmp;
	a[0]=strlen(tmp);
	for (int i=1;i<=a[0];i++){
		a[i]=tmp[a[0]-i]-'0';
	}
	cin>>tmp;
	b[0]=strlen(tmp);
	for (int i=1;i<=b[0];i++){
		b[i]=tmp[b[0]-i]-'0';
	}
	int n=max(a[0],b[0]);
	for (int i=1;i<=n;i++){
		a[i]+=b[i];
		a[i+1]+=a[i]/10;
		a[i]%=10;
//		cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<a[i+1]<<endl;
	}
	if (a[n+1]>0) n++;
	for (int i=n;i>=1;i--) printf("%d",a[i]);
	printf("\n");
	return 0;
}
