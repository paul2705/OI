#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x,y,z,n,p,d,w;
int main(){
	int cnt=0;
//	while (1){
//		cnt++;
//		cout<<cnt<<endl;
//		system("./getC");
//		system("./C");
		freopen("1.in","r",stdin);
		cin>>n>>p>>w>>d;
		freopen("1.out","r",stdin);
		cin>>x>>y>>z;
		cout<<x<<" "<<y<<" "<<z<<endl;
		cout<<n<<" "<<p<<" "<<w<<" "<<d<<endl;
//		freopen("B.cp","r",stdin);
		if (x==-1) return 0;
		if (x<0||y<0||z<0) printf("OPS! NEG\n"),cout<<x<<" "<<y<<" "<<z<<endl;
		if (x+y+z!=n) printf("OPS! OVER N\n"),cout<<x<<" "<<y<<" "<<z<<" "<<n<<endl;
		if (x*w+y*d!=p) printf("OPS! NEQ p\n"),cout<<x<<" "<<w<<" "<<y<<" "<<d<<" "<<p<<endl;
//		if (x+y+z==n&&x*w+y*d==p) continue;
//		else break;
//		fclose(stdin);
//	}
	return 0;
}
