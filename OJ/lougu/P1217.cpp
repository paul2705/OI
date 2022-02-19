#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int l,r;
int main(){
	scanf("%d%d",&l,&r);
	for (int i=1;;i++){
		int tmp=0,res=i;
		cout<<i<<" ";
		while (res>=10){
			tmp=tmp*10+res%10;
			res/=10;
		}
		res=i;
		while (res) tmp*=10,res/=10;
		tmp+=i;
		cout<<tmp<<endl;
		if (tmp>r) break;
		bool fg=1;
		for (int j=2;j*j<=tmp;j++){
			if (tmp%j==0) fg=0;
		}
		if (fg&&tmp>=l) printf("%d\n",tmp);
	}
	return 0;
}
