#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
typedef long long ll;
ll n,m,k;
int main(){
	srand(time(0));
	freopen("1.in","w",stdout);
	n=rand()%(ll)1e9;
	m=rand()%(ll)1e9;
	k=rand()%(ll)1e9;
	cout<<n<<" "<<m<<" "<<k<<endl;
	return 0;
}
