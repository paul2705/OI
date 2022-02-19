#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=1e5+5;
int main(){
	freopen("bzoj4977.in","w",stdout);
	srand(time(0));
	int n=rand()%mod+1,m=rand()%mod+1;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		int x=rand()%mod+1;
		cout<<x<<" ";
	}
	cout<<endl;
	for (int i=1;i<=m;i++){
		int x=rand()%mod+1,y=rand()%mod+1;
		cout<<x<<" "<<y<<endl;
	}
	fclose(stdout);
	return 0;
}
