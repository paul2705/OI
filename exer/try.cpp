#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
float a=0.1;
int main(){
	cout<<int(2.0-(double)0.1*0.1*100.0)<<endl;
	int ans=round(2-a*a*100);
	printf("%d\n",ans);
	printf("%.5f %d\n",3-a*a*100,int(3-a*a*100));
	return 0;
}
