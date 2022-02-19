#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct rec{
	long long lim,dat;
} a[5];
int main(){
	freopen("mixmilk.in","r",stdin);
	freopen("mixmilk.out","w",stdout);
	for (int i=0;i<=2;i++) scanf("%lld%lld",&a[i].lim,&a[i].dat);
	for (int i=0;i<100;i++){
		int x=i%3,y=(i+1)%3;
//		cout<<x<<" "<<y<<endl;
		if (a[x].dat+a[y].dat>a[y].lim){
			a[x].dat-=a[y].lim-a[y].dat;
			a[y].dat=a[y].lim;
		}
		else {
			a[y].dat+=a[x].dat; a[x].dat=0ll;
		}
//		cout<<x<<" "<<a[x].dat<<endl;
//		cout<<y<<" "<<a[y].dat<<endl<<endl;
	}
	for (int i=0;i<3;i++) printf("%lld\n",a[i].dat);
	fclose(stdin); fclose(stdout);
	return 0;
}
