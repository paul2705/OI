#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[15];
ll ansl,ansr;
int main(){
//	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	freopen("gift.in","r",stdin);
	freopen("gift.ans","w",stdout);
	for (int i=1;i<=4;i++) scanf("%lld",&a[i]);
	sort(a+1,a+5);
	for (int i=0;i<=50;i++){
		for (int j=i;j<=50;j++){
			for (int k1=1;k1<=4;k1++){
				a[k1]-=i;
				for (int k2=1;k2<=4;k2++){
					a[k2]-=i;
					for (int k3=1;k3<=4;k3++){
						a[k3]-=j;
						for (int k4=1;k4<=4;k4++){
							a[k4]-=j;
							bool fl=1;
							for (int l=1;l<=4;l++){
								if (a[l]<0) fl=0;
							}
							if (fl){
								if (ansl*ansr<=i*j){
									ansl=i,ansr=j;
								}
							}
							a[k4]+=j;
						}
						a[k3]+=j;
					}
					a[k2]+=i;
				}
				a[k1]+=i;
			}
		}
	}
	printf("%lld %lld\n",ansl,ansr);
	fclose(stdin); fclose(stdout);
	return 0;
}
