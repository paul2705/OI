#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	for (int i=1;i<=1000;i++){
		for (int j=1;j<=1000;j++){
			double x=i,y=j;
			double ans=x*x/2.0-x/2.0+x*y+y*y/2.0-3.0*y/2.0+1.0;
			if (ans==2018) printf("%d %d\n",i,j);
		}
	}
	return 0;
}
