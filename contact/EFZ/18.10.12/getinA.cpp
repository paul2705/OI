#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=3e3+6;
const int modn=3e3+5;
const int modc=26;
int main(){
	freopen("mayan.in","w",stdout);
	srand(time(0));
//	cout<<'{'-65<<endl;
	int n=rand()%modn+1,m=rand()%mod+1;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		int x=rand()%modc+1;
		int y=rand()%2;
//		cout<<x<<" ";
		if (y) x+=64;
		else x+=96;
		char c=x;
		cout<<c;
	}
	cout<<endl;
	for (int i=1;i<=m;i++){
		int x=rand()%modc+1;
		int y=rand()%2;
		if (y) x+=64;
		else x+=96;
		char c=x;
		cout<<c;
	}
	cout<<endl;
	return 0;
}
