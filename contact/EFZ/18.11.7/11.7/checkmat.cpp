#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinmar");
		system("./matrix");
		system("./matrix_bl");
		if (system("diff matrix.out matrix1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
