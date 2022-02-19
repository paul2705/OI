#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinpor");
		system("./portals_");
		system("./portals_bl");
		if (system("diff portals.out portals1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
