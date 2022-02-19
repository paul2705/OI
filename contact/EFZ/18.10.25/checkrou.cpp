#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinrou");
		system("./route");
		system("./route_bl");
		if (system("diff route.out route1.out")) break;
		if (cnt%100==0)cout<<cnt<<endl;
	}
	return 0;
}
