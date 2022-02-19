#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinsta");
		system("./station");
		system("./station_test");
		if (system("diff station.out station1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
