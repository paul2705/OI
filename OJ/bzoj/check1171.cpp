#include<iostream>
#include<cstdio>
using namespace std;
int cnt=1;
int main(){
	while (1){
		cout<<cnt<<endl;
		system("./getin1171");
		system("time ./bzoj1171");
		system("time ./bzoj1171_");
		if (system("diff bzoj1171.out bzoj1171_bl.out")) break;
		cnt++;
	}
	return 0;
}
